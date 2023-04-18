#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <limits> 
#include <ios>  

#define MAX_SIZE 6

using namespace std;

typedef struct
{
    int frente;
    int fim;
    int arr[MAX_SIZE];
} Deque;


Deque* createDeque()
{
	Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->fim = MAX_SIZE/2;
	deque->frente = MAX_SIZE/2+1;
	return deque;
}

bool vazio(Deque* deque)
{
	return (deque->frente == deque->fim + 1);
}

bool cheio(Deque* deque)
{
    return ((deque->frente + MAX_SIZE) - 1 == deque->fim);
}
    
void inserir_final(int dado, Deque* deque)
{
	if(cheio(deque))
	{
		cout << "Fila cheia" << endl;
		system("pause");
		return;
	}
	else
	{
		if(deque->fim == MAX_SIZE - 1)
		{
			for(int i = deque->frente; i <= deque->frente; i++)
			{
				deque->arr[i - 1] = deque->arr[i];
			}
			deque->arr[deque->fim] = dado;
			deque->frente--;
		}
		else
		{
    		deque->fim++;
    		deque->arr[deque->fim] = dado;
		}
	}
}
    
void remover_final(Deque* deque)
{
	if(vazio(deque))
	{
		cout << "Fila vazia" << endl;
	}
	else
	{	
		deque->fim--;
		cout << "Item removido" << endl;
	}
}
    
void inserir_frente(int dado, Deque* deque)
{
	if(cheio(deque))
	{
		cout << "Fila cheia" << endl;
		system("pause");
		return;
	}
	else
	{
		if(deque->frente == 0)
		{
			for(int i = deque->fim; i >= deque->frente; i--)
			{
				deque->arr[i + 1] = deque->arr[i];
			}
			deque->arr[deque->frente] = dado;
			deque->fim++;
		}
		else
		{
    		deque->frente--;
    		deque->arr[deque->frente] = dado;
    	}
    }
}
    
void remover_frente(Deque* deque)
{
    if(vazio(deque))
	{
		cout << "Fila vazia" << endl;
	}
	else
	{	
		deque->frente++;
		cout << "Item removido" << endl;
	}
}
    
void imprimir(Deque* deque)
{
	if(vazio(deque))
	{
		cout << "Fila vazia" << endl;
	}
	else
	{
	    for(int i = deque->frente; i <= deque->fim; i++)
	    {
	        cout << deque->arr[i] <<" ";
	    }
	    cout << endl;
	}
}
    
int main()
{
    Deque* deq1 = createDeque();
    int esc, c, dado, ext;

    while(ext != 1)
    {
    	system("cls");
        cout<<"1) inserir na frente"<<endl;
        cout<<"2) inserir no final"<<endl;
        cout<<"3) remover da frente"<<endl;
        cout<<"4) remover do final"<<endl;
        cout<<"5) imprimir"<<endl;
        cout<<"6) sair"<<endl;
        cout<<"Insira o comando"<<endl;
        
        while(!(cin >> esc))
		{
        cout << "Comando invalido, tente de novo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch(esc)
        {
	        case 1:
	            cout << "Insira o dado" << endl;
	            cin >> dado;
	            inserir_frente(dado, deq1);
	            break;
	        case 2:
	            cout << "Insira o dado" << endl;
	            cin >> dado;
	            inserir_final(dado, deq1);
	            break;
	        case 3:
	            remover_frente(deq1);
	            system("pause");
	            break;
	        case 4:
	            remover_final(deq1);
	            system("pause");
	            break;
	        case 5:
	        	system("cls");
	            imprimir(deq1);
	            system("pause");
	            break;
	        case 6:
	            ext = 1;
	            break;
	        default:
	            cout << "Comando invalido, tente de novo:" << endl;
	            system("pause");
				break;
	    }
    }
    return 0;
}