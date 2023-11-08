#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 5

typedef enum
{
    FAUX = 0,
    VRAI = 1
} bool;

#define DECLARER_PILE(TYPE)                                   \
    typedef struct Pile##TYPE                                 \
    {                                                         \
        TYPE pile[TAILLE_MAX];                                \
        TYPE *top;                                            \
    } Pile##TYPE##_t;                                         \
    void empiler##TYPE(TYPE valeur, struct Pile##TYPE *this); \
    TYPE depiler##TYPE(struct Pile##TYPE *this);              \
    bool estVide##TYPE(struct Pile##TYPE *this);              \
    TYPE sommet##TYPE(struct Pile##TYPE *this);

#define IMPLEMENTER_PILE(TYPE)                               \
    void empiler##TYPE(TYPE valeur, struct Pile##TYPE *this) \
    {                                                        \
        if (this->top == NULL)                               \
        {                                                    \
            this->top = this->pile;                          \
        }                                                    \
                                                             \
        if (this->top - this->pile < TAILLE_MAX)             \
        {                                                    \
            *(this->top) = valeur;                           \
            this->top++;                                     \
        }                                                    \
    }                                                        \
                                                             \
    TYPE depiler##TYPE(struct Pile##TYPE *this)              \
    {                                                        \
        if (this->top != NULL)                               \
        {                                                    \
            TYPE valeur = *(this->top - 1);                  \
            this->top--;                                     \
            if (this->top == this->pile)                     \
            {                                                \
                this->top = NULL;                            \
            }                                                \
            return valeur;                                   \
        }                                                    \
        else                                                 \
        {                                                    \
            return (TYPE)0;                                  \
        }                                                    \
    }                                                        \
                                                             \
    bool estVide##TYPE(struct Pile##TYPE *this)              \
    {                                                        \
        return (this->top == NULL);                          \
    }                                                        \
                                                             \
    TYPE sommet##TYPE(struct Pile##TYPE *this)               \
    {                                                        \
        if (this->top != NULL)                               \
        {                                                    \
            return *(this->top - 1);                         \
        }                                                    \
        else                                                 \
        {                                                    \
            return (TYPE)0;                                  \
        }                                                    \
    }
;

DECLARER_PILE(int)
DECLARER_PILE(float)
IMPLEMENTER_PILE(int)
IMPLEMENTER_PILE(float)

#endif
