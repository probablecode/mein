#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_
typedef struct MonomialType 
{
	int	degree;
	int coefficient;
} Monomial;

typedef struct TermType
{
	Monomial			mData;
	struct TermType*	pLLink;
	struct TermType*	pRLink;
} Term;

typedef struct PolynomialType{
	int		currentElementCount;
	Term	headerTerm;
} Polynomial;

typedef Polynomial	DoublyList;
typedef Term	DoublyListNode;

DoublyList* createDoublyList();
void deleteDoublyList(DoublyList* pList);
int addDLElement(DoublyList* pList, int position, DoublyListNode element);
int removeDLElement(DoublyList* pList, int position);
void clearDoublyList(DoublyList* pList);
int getDoublyListLength(DoublyList* pList);
DoublyListNode* getDLElement(DoublyList* pList, int position);
void displayPolynomial(Polynomial *pPoly);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1
#endif
