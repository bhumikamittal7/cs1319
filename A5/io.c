/*
Used reference from qemu (xv6) code I wrote last semester for OS class. It's already uploaded on my github on a private repo.
Also took help from gcc documentations and code.
Links as follows:
https://gcc.gnu.org/onlinedocs/libstdc++/manual/io.html
https://github.com/bhumikamittal7/cs1217/blob/master/lab2/printf.c  (puttig this fo my ref - you might not be able to access it)

 */

int printStr(char *inputString)
{
    int length = 0;
    for (length = 0; inputString[length] != '\0'; length++)
        ;
    __asm__ __volatile__("syscall" ::"a"(1), "D"(1), "S"(inputString), "d"(length)); // syscall for write (syntax: syscall, syscall number, destination, source, length)
    return length;
}

int printInt(int number)
{
    char buffer[100];
    int index = 0, j, k, bytes;

    if (number == 0)
        buffer[index++] = '0';
    else
    {
        if (number < 0)
        {
            buffer[index++] = '-';
            number = -number;
        }

        int digit = 0;
        while (number)
        {
            digit = number % 10;
            buffer[index++] = (char)(digit + '0');
            number /= 10;
        }

        if (buffer[0] != '-')
            j = 0;
        else
            j = 1;

        k = index - 1;
        char temp;

        while (j < k)
        {
            temp = buffer[j];
            buffer[j++] = buffer[k];
            buffer[k--] = temp;
        }
    }

    bytes = index;

    __asm__ __volatile__(
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(buffer), "d"(bytes));

    return bytes;
}

int readInt(int *eP)
{
    char buffer[1];
    char digits[20];
    int num = 0, length = 0, i;

    while (1)
    {
        __asm__ __volatile__("syscall" ::"a"(0), "D"(0), "S"(buffer), "d"(1));

        if (buffer[0] == '\t' || buffer[0] == '\n' || buffer[0] == ' ')
            break;

        else if (((int)buffer[0] - '0' > 9 || (int)buffer[0] - '0' < 0) && buffer[0] != '-')
            *eP = 1;

        else
            digits[length++] = buffer[0];
    }

    if (length > 9 || length == 0)
    {
        *eP = 1;
        return 0;
    }

    if (digits[0] == '-')
    {
        if (length == 1)
        {
            *eP = 1;
            return 0;
        }

        for (i = 1; i < length; i++)
        {
            if (digits[i] == '-')
                *eP = 1;
            num *= 10;
            num += (int)digits[i] - '0';
        }

        num = -num;
    }
    else
    {
        for (i = 0; i < length; i++)
        {
            if (digits[i] == '-')
                *eP = 1;
            num *= 10;
            num += (int)digits[i] - '0';
        }
    }

    return num;
}
