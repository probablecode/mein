#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

typedef	struct MonomialType
{
	int	degree;
	int	coefficient;
} Monomial;

typedef struct TermType
{
	Monomial data;
	struct TermType	*pLink;
} Term;

typedef struct PolynomialType
{
	int	currentElementCount;
	Term	headerNode;
} Polynomial;

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1
#endif

Term	*addTerm(Term *t1, Term *t2);	
Term	*mulTerm(Term *t1, Term *t2);
Polynomial	*createPolynomial(void);
void deleteTerm(Term *term);// 모든 Term은 coefficient 0이 되면 소멸한다. 이는 모든 종류의 연산에 마지막으로 들어있는게 좋겠다.
void clearPolynomial(Polynomial* pPoly);
void deletePolynomial(Polynomial* pPoly);
int	getPolynomialLength(Polynomial* pPoly);
Polynomial	*copyPolynomial(Polynomial *pPoly);
int addPElement(Polynomial* pPoly, Monomial element);
void printSuperScript(int i);
void displayMonomial(Monomial data);
void displayPolynomial(Polynomial *pPoly);
Polynomial	*addPolynomial(Polynomial *pPoly1, Polynomial *pPoly2);
Polynomial	*mulMonomial(Polynomial *pPoly1, Monomial element);
Polynomial	*subPolynomial(Polynomial *pPoly1, Polynomial *pPoly2);
Polynomial	*mulPolynomial(Polynomial *pPoly1, Polynomial *pPoly2);
Polynomial	*powerPolynomial(Polynomial *pPoly1, int power);

/*



//bonus///////////////////////////////////////////////////////////////////////////////////
Polynomial	*mulMonomial(Polynomial	*pPoly, Monomial element);
Polynomial	*mulPolynomial(Polynomial *pPoly1, Polynomial *pPoly2);
//
Polynomial	*subPolynomial(Polynomial *pPoly1, Polynomial *pPoly2);
//
Polynomial	*powerPolynomial(Polynomial *pPoly1, int power);
// final boss
Polynomial	*divPolynomial(Polynomial *dividend, Polynomial *dividor, Polynomial *remainder);*/
