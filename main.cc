/**
 * @brief Resuelve un sodoku usando backtracking
 * 
 * Esta funcion busca una celda vacia (que contenga 0)
 * Para cada celda vacia intenta colocar los numero del 1 al 9 y
 * valida si el numero es valido segun las reglas del sudoku
 * fila, columna, cuadrante 3x3
 * 
 * si colocar un numero conduce a una solucion valida, 
 * la funcion retorna true propagando la solucion hacia arriba.
 * 
 * si no es posible avanzar con un numero, se desahace el movimiento asignando nuevamente 0 a la celda
 * e intenta con otro numero
 * 
 * @param sudoku la matriz de 9x9 que representa el sudoku
 * @return true si el sudoku se resolvio correctamente
 * @return false si no existe solucion valida desde la configuracion actual
 * 
 * @author Alfredo Franco
 * 
 * 
 */

 //librerias y ficheros
#include "funciones.h"
#include <stdbool.h>
///funciones globales
#define rows 9
#define columns 9


//Declaracion del sudoku
int sudoku[rows][columns]=  {{1,4,6,0,0,7,9,0,0,},
                            {5,3,7,9,0,0,0,2,0,},
                            {2,8,9,0,6,0,0,4,0,},
                            {8,5,4,0,3,0,0,0,1,},
                            {9,2,1,8,0,0,0,0,0,},
                            {7,6,3,0,4,0,0,8,0,},
                            {4,9,5,6,1,8,7,3,2,},
                            {6,1,2,4,7,3,8,9,5,},
                            {3,7,8,2,9,5,6,1,4 },};
///Prototipo de funciones
void mostrar_sudoku(int sudoku[rows][columns]);
bool check_column(int sudoku[rows][columns],int column,int num);
bool check_row(int sudoku[rows][columns],int row,int num);
bool check_square(int sudoku[rows][columns],int row,int column);
bool check_all(int sudoku[rows][columns],int row,int column,int num);
bool check_vacio(int sudoku[rows][columns],int& row,int&column);
bool solve_sudoku(int sudoku[rows][columns] );

///Programa principal
int main(){
    int x=0, y=0;
    bool res =false;
    mostrar_sudoku(sudoku);
    std::cout<<"Proceso de resolucion.\n";
    
    std::cout<<"---------------------------------\n"<<res;
     res =solve_sudoku(sudoku);
    mostrar_sudoku(sudoku);
   std::cout<<"Resuelto: "<<res<<std::endl;

    
    return 0;
}