
#include "Queue.h"


/**
 * @brief Crea una cola nueva.
 */
Queue* Queue_New( int size )
{
    Queue* q = malloc( sizeof( Queue ) );

    if( q )
    {
        q->front = q->back = q->len = 0;
        q->size = size;

        q->q = (int*) malloc( size * sizeof( int ) );
        if( ! q->q )
        {
            free( q );
        }
    }

    return q;
}

/**
 * @brief Destruye una cola existente.
 *
 * @param this Referencia a un objeto Queue
 */
void Queue_Delete( Queue** this )
{
    assert( *this );

    free( (*this)->q );
    free( *this );
    *this = NULL;
}

/**
 * @brief Inserta un elemento en la cola.
 *
 * @param this Referencia a un objeto Queue.
 * @param value El valor a insertar.
 *
 * @return false si se agotó la memoria y el valor no se pudo insertar. true en
 * caso contrario.
 */
void Queue_Enqueue( Queue* this, int value )
{
    assert( this->len < this->size );

    this->q[ this->back ] = value;
    ++this->len;
    ++this->back;
    this->back = this->back % this->size;
}

/**
 * @brief Extrae un elemento de la cola.
 *
 * @param this Referencia a un objeto Queue.
 * @param value Receptáculo para el valor extraído.
 *
 * @return false si la cola está vacía. true en caso contrario.
 */
int Queue_Dequeue( Queue* this )
{
    assert( this->len > 0 );

    int tmp = this->q[ this->front ];

    --this->len;
    ++this->front;
    this->front = this->front % this->size;
    return tmp;
}


/**
 * @brief 'Observa' al valor en el frente de la cola.
 *
 * @param this Referencia a un objeto Queue.
 * @param value Receptáculo para el valor observado.
 *
 * @return false si la cola está vacía. true en caso contrario.
 */
int Queue_Peek( Queue* this )
{
    assert( this->len > 0 );

    return this->q[ this->front ];
}

/**
 * @brief Indica si la cola está vacía o no.
 *
 * @param this Referencia a un objeto Queue.
 *
 * @return true si la cola está vacía. false en caso contrario.
 */
bool Queue_IsEmpty( Queue* this )
{
    return this->len == 0;
}

/**
 * @brief Indica el número de elementos actuales en la cola.
 *
 * @param this Referencia a un objeto Queue.
 *
 * @return El número de elementos actualmente en la cola.
 */
size_t Queue_Len( Queue* this )
{
    return this->len;
}

