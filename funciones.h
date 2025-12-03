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

//librerias
#include <iostream>

//@def rows
//numero de filas(9)
#define rows 9
//@def columnas
//numero de filas(9)
#define columns 9

//si no existen que se generen
#ifndef FUNCIONES_H
#define FUNCIONES_H

//Declaracion de prototipo de funciones
void mostrar_sudoku(int sudoku[rows][columns]);
bool check_column(int sudoku[rows][columns], int row, int column);
bool check_row(int sudoku[rows][columns], int row, int column);
bool check_square(int sudoku[rows][columns], int row, int column,int num);
bool check_all(int sudoku[rows][columns], int row, int column);
bool check_vacio(int sudoku[rows][columns],int &row,int &column);
bool solve_sudoku(int sudoku[rows][columns] );

#endif

/// @brief mostrar sudoku
/// @param matriz sudoku 9x9
void mostrar_sudoku(int sudoku[rows][columns]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            std::cout<<sudoku[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

/**
 * @brief Revisar si existe un numero en un cierta columna
 * @param sudoku 9x9
 * @param columna actual
 * @param numero a revisar
 * 
 * @return true si el numero ya esta previamente en esa columna
 * @return false si no existe y se puede añadir
 */

bool check_column(int sudoku[rows][columns],int column,int num){
    for(int i=0;i<rows;i++){
        if(sudoku[i][column]==num){
            return true;
        }
    }
    return false;
}

/**
 * @brief Revisar si existe un numero en un cierta fila
 * @param sudoku 9x9
 * @param fila actual
 * @param numero a revisar
 * 
 * @return true si el numero ya esta previamente en esa fila
 * @return false si no existe y se puede añadir
 */

bool check_row(int sudoku[rows][columns],int row,int num){
    for(int i=0;i<columns;i++){
        if(sudoku[row][i]==num){
            return true;
        }
    }
    return false;
}

/**
 * @brief Revisar si existe un numero en un cierto cuadrante
 * @param sudoku 9x9
 * @param columna actual
 * @param fila actual
 * @param numero a revisar
 * 
 * @return true si el numero ya esta previamente en ese cuadrante
 * @return false si no existe y se puede añadir
 */

bool check_square(int sudoku[rows][columns],int row,int column,int num){
    int option;
    option=(row/3)+((column/3)*3);
    switch(option){
        case 0:
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(sudoku[i][j]==num){
                        return true;
                    }
                }
            }
            break;
        case 1:
            for(int i=3;i<6;i++){
                for(int j=0;j<3;j++){
                    if(sudoku[i][j]==num){
                        return true;
                    }
                }
            }
            break;
        case 2:
            for(int i=6;i<9;i++){
                for(int j=0;j<3;j++){
                    if(sudoku[i][j]==num){
                        return true;
                    }
                }
            }
            break;
        case 3:
            for(int i=0;i<3;i++){
                for(int j=3;j<6;j++){
                    if(sudoku[i][j]==num){
                        return true;
                    }
                }
            }
            break;
        case 4:
            for(int i=3;i<6;i++){
                for(int j=3;j<6;j++){
                    if(sudoku[i][j]==num){
                        return true;
                    }
                }
            }
            break;
        case 5:
            for(int i=6;i<9;i++){
                for(int j=3;j<6;j++){
                    if(sudoku[i][j]==num){
                        return true;
                    }
                }
            }
            break;
        case 6:
            for(int i=0;i<3;i++){
                for(int j=6;j<9;j++){
                    if(sudoku[i][j]==num){
                        return true;
                    }
                }
            }
            break;
        case 7:
            for(int i=3;i<6;i++){
                for(int j=6;j<9;j++){
                    if(sudoku[i][j]==num){
                        return true;
                    }
                }
            }
            break;
        case 8:
            for(int i=6;i<9;i++){
                for(int j=6;j<9;j++){
                    if(sudoku[i][j]==num){
                        return true;
                    }
                }
            }
            break;
        default: std::cout<<"\nIndice no encontrado\n";
        break;

    }
    return false;
}

/**
 * @brief Revisar si existe un numero en esa columna, fila o cuadrante 
 * a partir de las funciones anteriores.
 * 
 * @param sudoku 9x9
 * @param columna actual
 * @param fila actual
 * @param numero a revisar
 * 
 * @return true si el numero ya esta previamente en esa fila, columna o cuadrante
 * @return false si no existe y se puede añadir
 */

bool check_all(int sudoku[rows][columns],int row,int column,int num){
    
    if(check_column(sudoku,column,num)==true){
        return true;
    }
    else if(check_row(sudoku,row,num)==true){
        return true;
    }
    else if(check_square(sudoku,row, column,num)==true){
        return true;
    }

    return false;
}

/**
 * @brief Revisar si existe una celda de la matriz que este vacia (que sea 0)
 * y modifica el valor de las coordenadas ya que se pasan por referencia
 * 
 * @param sudoku 9x9
 * @param columna actual
 * @param fila actual
 * 
 * @return true si hay alguna celda vacia
 * @return false si esta lleno el sudoku
 */

bool check_vacio(int sudoku[rows][columns],int &row, int &column){
    for(row =0;row<rows;row++){
        for(column=0;column<columns;column++){
            if(sudoku[row][column]==0){
                //std::cout<<"Encontrado\n";
                return true;
            }
        }
    }
    std::cout<<"No encontrado\n";
    return false;
}


/**
 * @brief Resolver el sudoku
 * Esta funcion engloba todas las anteriores crea las variables 
 * de fila y columna que manda a la funcion de checar vacio para
 * ver si hay elementos pendientes de rellenar en la funcion y posteriormente
 * si hay al menos uno,
 * 
 * pasa a un ciclo for para revisar del 1 al 9 si un elemento de puede 
 * agregar a una celda dada con la funcion 
 * check all que nos devuelve un false si no esta ese numero
 * 
 * finalmente si no se puede resolver con un numero dado volvemos a
 * colocar 0 en la celda  y retornamos false para que en el backtracking 
 * intente con otro numero, haste que se pueda resolver el sudoku y retornar true.
 * 
 * @param sudoku 9x9
 * 
 * 
 * @return true si fue resuelto el sudoku
 * @return false si en la posicion dada no se pudo resolver.
 */

bool solve_sudoku(int sudoku[rows][columns]){
    int row,column;
    if(check_vacio(sudoku,row,column)==false){
        std::cout<<"vacio\n";
        return true;
        }
    for(int i=1;i<=9;i++){
       if(check_all(sudoku,row,column,i)==false){
            sudoku[row][column]=i;
            if(solve_sudoku(sudoku)){
                return true;
            }
       
             sudoku[row][column]=0;
            }
    }
     return false;  
}