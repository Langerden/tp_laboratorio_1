/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;
#endif



/**
 *  \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void);

/**
 * \brief Retorna la cantidad de elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 */
int ll_len(LinkedList* this);

/**
 * \brief  Permite realizar el test de la funcion getNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL
 * 							 o (si el indice es menor a 0 o mayor al len de la lista)
 * 							 (pElement) Si funciono correctamente
 */
Node* test_getNode(LinkedList* this, int nodeIndex);

/**
 * \brief Permite realizar el test de la funcion addNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/**
 * \brief  Agrega un elemento al final de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_add(LinkedList* this, void* pElement);

/**
 * \brief Retorna un puntero al elemento que se encuentra en el índice especificado.
 * 			Verificando que el puntero this sea distinto de NULL
 *		 	y que index sea positivo e inferior al tamaño del array.
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a obtener
 * \return void* Si la verificación falla retorna (NULL) y si tiene éxito retorna el elemento.
 */
void* ll_get(LinkedList* this, int index);

/**
 * \brief Inserta un elemento en el LinkedList, en el índice especificado.
 * 			Verificando que el puntero this sea distinto de NULL
 * 			y que index sea positivo e inferior al tamaño del array
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Si la verificación falla retorna (-1) y si tiene éxito (0).
 */
int ll_set(LinkedList* this, int index,void* pElement);

/**
 * \brief Elimina un elemento de la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 * 						o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_remove(LinkedList* this,int index);

/**
 * \brief Elimina todos los nodos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_clear(LinkedList* this);

/**
 *  \brief Elimina todos los elementos de la lista y la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_deleteLinkedList(LinkedList* this);

/**
 * \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 */
int ll_indexOf(LinkedList* this, void* pElement);

/**
 * \brief Indica si la lista esta o no vacia
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 */
int ll_isEmpty(LinkedList* this);

/**
 * \brief Inserta un nuevo elemento en la lista en la posicion indicada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 * 						o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_push(LinkedList* this, int index, void* pElement);

//elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
/**
 * \brief Elimina el elemento de la posicion indicada y retorna su puntero
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL
 * 							o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 */
void* ll_pop(LinkedList* this,int index);

/**
 * \brief  Determina si la lista contiene o no el elemento pasado como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement);

/**
 * \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2);

/**
 * \brief Crea y retorna una nueva lista con los elementos indicados
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         	 	(puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to);

/**
 * \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this);

/**
 * \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

/**
 * @brief Permite modificar un campo de todos los elementos
 *
 * @param this: Puntero a la lista
 * @param pFunc: Puntero a la funcion criterio
 * @return (NULL) Error: si el puntero a la listas es NULL
				(puntero a la nueva lista) Si ok
 */
LinkedList* ll_map(LinkedList* this, void (*pFunc)(void*));

/**
 * @brief Filtra los elementos de la lista
 * @param this: lista a filtrar
 * @param pFunc: puntero a funcion con la condicion a filtrar
 * 				retorna 1 (si el elemento cumple la condicion) sino 0
 * @return Nueva LinkedList con elementos que cumplan la condicion a filtrar
 * 			o NULL en caso de error
 */
LinkedList* ll_filter (LinkedList* this, int (*pFunc)(void*));


