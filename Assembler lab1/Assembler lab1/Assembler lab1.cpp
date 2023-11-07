// Assembler lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
int A[9];
int i, j;
int main() {
    i = 0;
    /*while (i < 9) {
        j = 2 * i;
        switch (i) {
        case 5:j += 10; break;
        case 6: j *= 2; break;
        case 7: j -= 4; break;
        case 8: j = 7; break;
        default: j++;

        }
        A[i] = j;
        i++;
    }*/
    __asm {
        mov i, 0
        label:
        mov eax, i
            mov ecx, eax
            shl eax, 1
            mov j, eax
            cmp i, 5
            je case5

            cmp i, 6
            je case6

            cmp i, 7
            je case7

            cmp i, 8
            je case8
            add j, 1
            mov eax, j 
            
            jmp endswitch

            case5 :
        add j, 10
            mov eax, j
            jmp endswitch

            case6 :
        mov EAX, j
            shl EAX, 1
            
            jmp endswitch

            case7 :
            sub j, 4
                mov eax, j
            jmp endswitch

            case8 :
        mov j, 7
            mov eax, j
            jmp endswitch

            mov edx, 1

            add j, edx

            mov eax, j
            
            endswitch :
            
            mov A[ecx * 4], eax 
            inc i
            cmp i, 9
            jl label
    }
    for (i = 0; i < 9; i++)
        printf("%d ", A[i]);
    printf("\n");

    system("pause");
    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
