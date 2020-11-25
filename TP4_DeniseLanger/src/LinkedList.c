#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

//Crea una LinkedList nueva
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList)); //Reservo memoria dinamica
    if (this != NULL)
    {
    	this->size = 0; //Inicializo el size en 0
    	this->pFirstNode = NULL; //Puntero al primer nodo en NULL
    }
    return this; //retorna una nueva Linkedlist
}

//Largo del LinkedList
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size; //Retorna el size del LinkedList
    }
    return returnAux;
}

/**
 * \brief  Obtiene un nodo de la lista
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o
 * 								(si el indice es menor a 0 o mayor al len de la lista)
 * 								(pNode) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;

    if (this != NULL)
    {
    	if(nodeIndex >= 0 && (nodeIndex < ll_len(this)))//Valido parametros
    	{
    		pNode = this->pFirstNode; //inicializo pNode asignando el valor del primer nodo de this

    		while(nodeIndex > 0) //Iterar hasta el indice deseado
    		{
    			pNode = pNode->pNextNode; //Cargo el pNode (a retornar) con el puntero al indice deseado
    			nodeIndex--;
    		}
    	}
    }
	return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/**
 * \brief Agrega y enlaza un nuevo nodo a la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 * 						o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode;

    if(this != NULL && nodeIndex >= 0 && (nodeIndex <= ll_len(this)))//Validaciones
    {
    	newNode = (Node*) malloc(sizeof(Node)); //Creo un nuevo nodo (memoria dinamica)
    	if(newNode != NULL) //Valido
    	{
    		newNode->pElement = pElement; //Le asigno el Elemento
    		newNode->pNextNode = NULL;
    		if (nodeIndex == 0) //Si el indice es 0 (Primer elemento del Linkedlist)
    		{
    			newNode->pNextNode = this->pFirstNode; //Asigno el puntero al primero elemento
    			this->pFirstNode = newNode; // Nuevo pFirstNode de this es el creado
    		} else {
    			newNode->pNextNode = getNode(this, nodeIndex); //Obtengo el nodo actual (indice por paremetro) y se lo asigno al NextNode
    			(getNode(this, nodeIndex-1))->pNextNode = newNode; //Le paso al nodo previo la direccion del nodo nuevo, al que apuntara
    		}
    	}
    	this->size++; //Incremento el size de this
    	returnAux = 0;
    }
   return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

//Agrega un elemento a la lista
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement);
    }
    return returnAux;
}

//Obtiene el Elemento ubicado en la lista (indice por parametro)
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = getNode(this, index)->pElement;
    }
    return returnAux;
}

//Modifico un elemento de la lista
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index); //Obtengo el nodo
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement; //Le asigno el nuevo elemento al nodo
    		returnAux = 0;
    	}
    }
    return returnAux;
}

//Elimina un elemento de la lista
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;
	Node* actualNode;
	Node* previousNode;

	if (this != NULL && index < ll_len(this) && index >= 0)
	{
		actualNode = getNode(this, index); //Direccion de memoria actual del nodo
		if (actualNode != NULL )
		{
			if (index == 0) //Eliminar el primer nodo
			{
				this->pFirstNode = actualNode->pNextNode; //El FirstNode apunta al NextNode actual
			} else { //indice != 0
				previousNode = getNode(this, index - 1); //Direccion de memoria del nodo anterior
				if (previousNode != NULL)
				{
					previousNode->pNextNode = actualNode->pNextNode; //Cambio donde apunta el nodo siguiente
				}
			}
			this->size--; //Disminuyo el size de this
			free(actualNode);
			returnAux = 0;
		}
	}
	return returnAux;
}

//Elimina todos los elementos
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int index;

        if(this != NULL)
        {
            index = this->size;
            while(this->size > 0)
            {
                ll_remove(this, index);
                index--;
            }
            returnAux=0;
        }
    return returnAux;
}

//Elimina la Linkedlist completa
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(!ll_clear(this))
    	{
    		free(this); //Libero la memoria
    		returnAux = 0;
    	}
    }
    return returnAux;
}

//Retorna el indice donde aparece el elemento por primera vez
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if (this != NULL)
    {
    	for(int i = 0; i < ll_len(this); i++)
    	{
    		if (ll_get(this, i) == pElement)
    		{
				returnAux = i;
				break;
    		}
    	}
    }
    return returnAux;
}

//Indica si la lista esta vacia
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;
		if(!ll_len(this))
			returnAux = 1;
    }
    return returnAux;
}

//Inserta un nuevo elemento en la lista en la posicion indicada
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}

//Elimina el elemento de la posicion indicada y retorna su puntero
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    returnAux = ll_get(this, index);
    if(returnAux!= NULL)
    {
    	ll_remove(this, index);
    }
    return returnAux;
}

//Determina si la lista contiene o no el elemento pasado como parametro
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if (this!=NULL)
    {
	   returnAux = ll_indexOf(this,pElement);
	   if (returnAux == -1)
	   {
		   returnAux = 0;
	   } else {
		   returnAux = 1;
	   }
   }
   return returnAux;
}

//Determina si todos los elementos de la lista (this2) estan en la lista (this)
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    if (this != NULL && this2 != NULL)
    {
    	returnAux = 1;

    	for (int i = 0; i < ll_len(this2); i++)
    	{
    		if (!ll_contains(this, ll_get(this2, i)))
    		{
				returnAux = 0;
				break;
    		}
    	}
    }
    return returnAux;
}

//Crea y retorna una nueva lista desde/hasta los indices indicados por parametro
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;

    if(!(this == NULL || from < 0 || from > ll_len(this) || to <= from || to > ll_len(this)))
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		for(int i = from; i < to; i++)
    		{
    			pElement = ll_get(this, i);
    			ll_add(cloneArray, pElement);
    		}
    	}
    }
    return cloneArray;
}

//Clona una lista
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}

//Ordena los elementos de la lista segun la funcion (criterio) recibida por parametro
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElement1;
    void* pElement2;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	for(int a = 0; a < ll_len(this)-1; a++)
    	{
    		for(int b = a+1; b < ll_len(this); b++)
    		{
    			pElement1 = ll_get(this, a);
    			pElement2 = ll_get(this, b);

    			//1) Si el elemento1 > elemento2, y el orden es ascendente, hago swap
    			//2) Si el elemento1 < elemento2, y el orden es descendente, hago swap
    			if((pFunc(pElement1,pElement2) > 0 && order) //
    					|| (pFunc(pElement1,pElement2) < 0 && !order))
    			{
    				ll_set(this, a, pElement2); //Asigno el elemento2 al size-1
    				ll_set(this, b, pElement1); //Asigno el elemento1 al size
    			}
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;
}

//Crea una nueva Linkedlist, con un campo modificado por la funcion en todos los elementos
LinkedList* ll_map(LinkedList* this, void (*pFunc)(void*))
{
	LinkedList* auxLinkedList = NULL;
	void* pElement;

	if(this != NULL && pFunc != NULL)
	{
		auxLinkedList = ll_newLinkedList();

		for(int i = 0; i < ll_len(this); i++)
		{
			pElement = ll_get(this, i);
			pFunc(pElement);
			ll_add(auxLinkedList, pElement);
		}
	}
	return auxLinkedList;
}

//Crea una nueva Linkedlist (filrada) segun la funcion (criterio)
LinkedList* ll_filter (LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* auxLinkedList = NULL;
	void* pElement;

	if(this != NULL && pFunc != NULL)
	{
		auxLinkedList = ll_newLinkedList();
		if(auxLinkedList != NULL)
		{
			for(int i = 0; i < ll_len(this); i++)
			{
				pElement = ll_get(this, i);
				if(pFunc(pElement))
				{
					ll_add(auxLinkedList, pElement);
				}
			}
		}
	}
	return auxLinkedList;
}
