#include "1_A5_translator.h"
#include <iostream>
#include <cstring>
#include <string>

extern FILE *yyin;
extern vector<string> storeString;

using namespace std;

int labelCount = 0;
std::map<int, int> labelMap;
ofstream out;
vector<quad> Array;
string asmfilename = "test";
string inputfile = "test";

void ActivationRecord(symTable *st)
{
	int param = -20; // 4 for return value, 4 for return address, 8 for previous rbp, 4 for param count
	int local = -24; // 4 for return value, 4 for return address, 8 for previous rbp, 8 for return address

	for (list<sym>::iterator it = st->table.begin(); it != st->table.end(); it++)
	{

		if (it->category == "param")
		{
			st->array[it->name] = param;
			param += it->size;
		}
		else if (it->name == "return")
			continue;

		else
		{
			st->array[it->name] = local;
			local -= it->size;
		}
	}
}

void generateASM()
{
	Array = q.Array;

	for (vector<quad>::iterator it = Array.begin(); it != Array.end(); it++)
	{
		int i;
		if (it->op == "GOTO" || it->op == "LESS_THAN" || it->op == "GREATER_THAN" || it->op == "LESS_THAN_EQUAL_TO" || it->op == "GREATER_THAN_EQUAL_TO" || it->op == "EQUAL_TO" || it->op == "NOT_EQUAL_TO")
		{
			i = atoi(it->result.c_str());
			labelMap[i] = 1;
		}
	}
	int counter = 0;

	for (std::map<int, int>::iterator it = labelMap.begin(); it != labelMap.end(); ++it)
		it->second = counter++;
	list<symTable *> tablelist;

	for (list<sym>::iterator it = globalST->table.begin(); it != globalST->table.end(); it++)
	{
		if (it->nested != NULL)
			tablelist.push_back(it->nested);
	}

	for (list<symTable *>::iterator iterator = tablelist.begin();
		 iterator != tablelist.end(); ++iterator)
	{
		ActivationRecord(*iterator);
	}

	ofstream asmfile;
	asmfile.open(asmfilename.c_str());

	asmfile << "\t.file	\"test.c\"\n";
	for (list<sym>::iterator it = table->table.begin(); it != table->table.end(); it++)
	{
		if (it->category != "function")
		{

			if (it->type->type == "char")
			{
				if (it->val != "")
				{
					asmfile << "\t.globl\t" << it->name << "\n";
					asmfile << "\t.type\t" << it->name << ", @object\n";
					asmfile << "\t.size\t" << it->name << ", 1\n";
					asmfile << it->name << ":\n";
					asmfile << "\t.byte\t" << atoi(it->val.c_str()) << "\n";
				}
				else
				{
					asmfile << "\t.comm\t" << it->name << ",1,1\n";
				}
			}

			if (it->type->type == "int")
			{
				if (it->val != "")
				{
					asmfile << "\t.globl\t" << it->name << "\n";
					asmfile << "\t.data\n";
					asmfile << "\t.align 4\n";
					asmfile << "\t.type\t" << it->name << ", @object\n";
					asmfile << "\t.size\t" << it->name << ", 4\n";
					asmfile << it->name << ":\n";
					asmfile << "\t.long\t" << it->val << "\n";
				}
				else
				{
					asmfile << "\t.comm\t" << it->name << ",4,4\n";
				}
			}
		}
	}

	if (storeString.size())
	{
		asmfile << "\t.section\t.rodata\n";
		for (vector<string>::iterator it = storeString.begin(); it != storeString.end(); it++)
		{
			asmfile << ".LC" << it - storeString.begin() << ":\n";
			asmfile << "\t.string\t" << *it << "\n";
		}
	}

	asmfile << "\t.text	\n";

	vector<string> params;
	std::map<string, int> theMap;
	for (vector<quad>::iterator it = Array.begin(); it != Array.end(); it++)
	{
		if (labelMap.count(it - Array.begin()))
		{
			asmfile << ".L" << (2 * labelCount + labelMap.at(it - Array.begin()) + 2) << ": " << endl;
		}

		string op = it->op;
		string result = it->result;
		string arg1 = it->arg1;
		string arg2 = it->arg2;
		string s = arg2;

		if (op == "param")
		{
			params.push_back(result);
		}
		else
		{
			asmfile << "\t";

			if (op == "PLUS")
			{
				bool flag = true;
				if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
					flag = false;
				else
				{
					char *p;
					strtol(s.c_str(), &p, 10);
					if (*p == 0)
						flag = true;
					else
						flag = false;
				}
				if (flag)
				{
					asmfile << "addl \t$" << atoi(arg2.c_str()) << ", " << table->array[arg1] << "(%rbp)";
				}
				else
				{
					asmfile << "movl \t" << table->array[arg1] << "(%rbp), "
							<< "%eax" << endl;
					asmfile << "\tmovl \t" << table->array[arg2] << "(%rbp), "
							<< "%edx" << endl;
					asmfile << "\taddl \t%edx, %eax\n";
					asmfile << "\tmovl \t%eax, " << table->array[result] << "(%rbp)";
				}
			}

			else if (op == "MINUS")
			{
				asmfile << "movl \t" << table->array[arg1] << "(%rbp), "
						<< "%eax" << endl;
				asmfile << "\tmovl \t" << table->array[arg2] << "(%rbp), "
						<< "%edx" << endl;
				asmfile << "\tsubl \t%edx, %eax\n";
				asmfile << "\tmovl \t%eax, " << table->array[result] << "(%rbp)";
			}

			else if (op == "ASTERISK")
			{
				asmfile << "movl \t" << table->array[arg1] << "(%rbp), "
						<< "%eax" << endl;
				bool flag = true;
				if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
					flag = false;
				else
				{
					char *p;
					strtol(s.c_str(), &p, 10);
					if (*p == 0)
						flag = true;
					else
						flag = false;
				}
				if (flag)
				{
					asmfile << "\timull \t$" << atoi(arg2.c_str()) << ", "
							<< "%eax" << endl;
					symTable *t = table;
					string val;
					for (list<sym>::iterator it = t->table.begin(); it != t->table.end(); it++)
					{
						if (it->name == arg1)
							val = it->val;
					}
					theMap[result] = atoi(arg2.c_str()) * atoi(val.c_str());
				}
				else
					asmfile << "\timull \t" << table->array[arg2] << "(%rbp), "
							<< "%eax" << endl;
				asmfile << "\tmovl \t%eax, " << table->array[result] << "(%rbp)";
			}

			else if (op == "DIVIDE")
			{
				asmfile << "movl \t" << table->array[arg1] << "(%rbp), "
						<< "%eax" << endl;
				asmfile << "\tcltd" << endl;
				asmfile << "\tidivl \t" << table->array[arg2] << "(%rbp)" << endl;
				asmfile << "\tmovl \t%eax, " << table->array[result] << "(%rbp)";
			}

			else if (op == "MODULO")
				asmfile << result << " = " << arg1 << " % " << arg2;

			else if (op == "ASSIGN")
			{
				s = arg1;
				bool flag = true;
				if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
					flag = false;
				else
				{
					char *p;
					strtol(s.c_str(), &p, 10);
					if (*p == 0)
						flag = true;
					else
						flag = false;
				}
				if (flag)
					asmfile << "movl\t$" << atoi(arg1.c_str()) << ", "
							<< "%eax" << endl;
				else
					asmfile << "movl\t" << table->array[arg1] << "(%rbp), "
							<< "%eax" << endl;
				asmfile << "\tmovl \t%eax, " << table->array[result] << "(%rbp)";
			}
			else if (op == "ASSIGNSTR")
			{
				asmfile << "movq \t$.LC" << arg1 << ", " << table->array[result] << "(%rbp)";
			}
			else if (op == "ASSIGNCHAR")
			{
				asmfile << "movb\t$" << atoi(arg1.c_str()) << ", " << table->array[result] << "(%rbp)";
			}

			else if (op == "EQUAL_TO")
			{
				asmfile << "movl\t" << table->array[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->array[arg2] << "(%rbp), %eax\n";
				asmfile << "\tje .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "NOT_EQUAL_TO")
			{
				asmfile << "movl\t" << table->array[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->array[arg2] << "(%rbp), %eax\n";
				asmfile << "\tjne .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "LESS_THAN")
			{
				asmfile << "movl\t" << table->array[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->array[arg2] << "(%rbp), %eax\n";
				asmfile << "\tjl .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "GREATER_THAN")
			{
				asmfile << "movl\t" << table->array[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->array[arg2] << "(%rbp), %eax\n";
				asmfile << "\tjg .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "GREATER_THAN_EQUAL_TO")
			{
				asmfile << "movl\t" << table->array[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->array[arg2] << "(%rbp), %eax\n";
				asmfile << "\tjge .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "LESS_THAN_EQUAL_TO")
			{
				asmfile << "movl\t" << table->array[arg1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->array[arg2] << "(%rbp), %eax\n";
				asmfile << "\tjle .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "GOTO")
			{
				asmfile << "jmp .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}

			else if (op == "UMINUS")
			{
				asmfile << "negl\t" << table->array[arg1] << "(%rbp)";
			}

			else if (op == "[]")
			{
				int off = 0;
				off = theMap[arg2] * (-1) + table->array[arg1];
				asmfile << "movq\t" << off << "(%rbp), "
						<< "%rax" << endl;
				asmfile << "\tmovq \t%rax, " << table->array[result] << "(%rbp)";
			}
			else if (op == "=[]")
			{
				int off = 0;
				off = theMap[arg1] * (-1) + table->array[result];
				asmfile << "movq\t" << table->array[arg2] << "(%rbp), "
						<< "%rdx" << endl;
				asmfile << "\tmovq\t"
						<< "%rdx, " << off << "(%rbp)";
			}
			else if (op == "RETURN")
			{
				if (result != "")
					asmfile << "movl\t" << table->array[result] << "(%rbp), "
							<< "%eax";
				else
					asmfile << "nop";
			}
			else if (op == "param")
			{
				params.push_back(result);
			}

			else if (op == "call")
			{

				symTable *t = globalST->lookup(arg1)->nested;
				int i, j = 0;
				for (list<sym>::iterator it = t->table.begin(); it != t->table.end(); it++)
				{
					i = distance(t->table.begin(), it);
					if (it->category == "param")
					{
						if (j == 0)
						{

							asmfile << "movl \t" << table->array[params[i]] << "(%rbp), "
									<< "%eax" << endl;
							asmfile << "\tmovq \t" << table->array[params[i]] << "(%rbp), "
									<< "%rdi" << endl;
							j++;
						}
						else if (j == 1)
						{

							asmfile << "movl \t" << table->array[params[i]] << "(%rbp), "
									<< "%eax" << endl;
							asmfile << "\tmovq \t" << table->array[params[i]] << "(%rbp), "
									<< "%rsi" << endl;
							j++;
						}
						else if (j == 2)
						{

							asmfile << "movl \t" << table->array[params[i]] << "(%rbp), "
									<< "%eax" << endl;
							asmfile << "\tmovq \t" << table->array[params[i]] << "(%rbp), "
									<< "%rdx" << endl;
							j++;
						}
						else if (j == 3)
						{

							asmfile << "movl \t" << table->array[params[i]] << "(%rbp), "
									<< "%eax" << endl;
							asmfile << "\tmovq \t" << table->array[params[i]] << "(%rbp), "
									<< "%rcx" << endl;
							j++;
						}
						else
						{
							asmfile << "\tmovq \t" << table->array[params[i]] << "(%rbp), "
									<< "%rdi" << endl;
						}
					}
					else
						break;
				}
				params.clear();
				asmfile << "\tcall\t" << arg1 << endl;
				asmfile << "\tmovl\t%eax, " << table->array[result] << "(%rbp)";
			}

			else if (op == "FUNC")
			{

				asmfile << ".globl\t" << result << "\n";
				asmfile << "\t.type\t" << result << ", @function\n";
				asmfile << result << ": \n";
				asmfile << ".LFB" << labelCount << ":" << endl;
				asmfile << "\t.cfi_startproc" << endl;
				asmfile << "\tpushq \t%rbp" << endl;
				asmfile << "\t.cfi_def_cfa_offset 8" << endl;
				asmfile << "\t.cfi_offset 5, -8" << endl;
				asmfile << "\tmovq \t%rsp, %rbp" << endl;
				asmfile << "\t.cfi_def_cfa_register 5" << endl;
				table = globalST->lookup(result)->nested;
				asmfile << "\tsubq\t$" << table->table.back().offset + 24 << ", %rsp" << endl;

				symTable *t = table;
				int i = 0;
				for (list<sym>::iterator it = t->table.begin(); it != t->table.end(); it++)
				{
					if (it->category == "param")
					{
						if (i == 0)
						{
							asmfile << "\tmovq\t%rdi, " << table->array[it->name] << "(%rbp)";
							i++;
						}
						else if (i == 1)
						{
							asmfile << "\n\tmovq\t%rsi, " << table->array[it->name] << "(%rbp)";
							i++;
						}
						else if (i == 2)
						{
							asmfile << "\n\tmovq\t%rdx, " << table->array[it->name] << "(%rbp)";
							i++;
						}
						else if (i == 3)
						{
							asmfile << "\n\tmovq\t%rcx, " << table->array[it->name] << "(%rbp)";
							i++;
						}
					}
					else
						break;
				}
			}

			else if (op == "FUNCEND")
			{
				asmfile << "leave\n";
				asmfile << "\t.cfi_restore 5\n";
				asmfile << "\t.cfi_def_cfa 4, 4\n";
				asmfile << "\tret\n";
				asmfile << "\t.cfi_endproc" << endl;
				asmfile << ".LFE" << labelCount++ << ":" << endl;
				asmfile << "\t.size\t" << result << ", .-" << result;
			}
			else
				asmfile << "op";
			asmfile << endl;
		}
	}

	asmfile << "\t.ident\t	\"Bhumika's Compiler LOL - please reach here\"\n";
	asmfile.close();
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
	copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
	return os;
}

int main(int ac, char *av[])
{
	inputfile = inputfile + string(av[ac - 1]) + string(".nc");
	asmfilename = asmfilename + string(av[ac - 1]) + string(".asm");
	globalST = new symTable("Global");
	table = globalST;
	yyin = fopen(inputfile.c_str(), "r");
	yyparse();
	globalST->update();
	globalST->print();
	q.print();
	generateASM();
}