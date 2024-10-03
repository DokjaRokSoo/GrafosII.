/*Copyright (C) 
 * 2019 - eda1 dot fiunam at yahoo dot com dot mx
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

/**
 * @file 
 * @brief 
 * @author eda1 dot fiunam at yahoo dot com dot mx
 * @version 0.1
 * @date 29/ago/19
 */

#ifndef  QUEUE_INC
#define  QUEUE_INC


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//#include "DLL.h"
// Item está definida aquí

typedef struct 
{
    int* q;
    int front;
    int back;
    int len;
    int size;
} Queue;

Queue* Queue_New();
void   Queue_Delete(    Queue* *this );
void   Queue_Enqueue(   Queue* this, int value );
int    Queue_Dequeue(   Queue* this );
int    Queue_Peek(      Queue* this );
bool   Queue_IsEmpty(   Queue* this );
bool   Queue_IsFull(    Queue* this );
size_t Queue_Len(       Queue* this );


#endif   /* ----- #ifndef QUEUE_INC  ----- */
