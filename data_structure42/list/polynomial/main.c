#include "polynomial.h"
#include <stdio.h>
int	main(void)
{
	Polynomial	*poly1;
	Polynomial	*poly2;
	Polynomial	*ret;
	Monomial	element;
	element.coefficient = 1;
	element.degree = 0;

	poly1 = createPolynomial();
	for (int i = 0; i < 3; i++)
	{
		printf("[a]adding element [%dx^%d's return]:%d\n ", element.coefficient, element.degree,addPElement(poly1, element));
		element.coefficient++;
		element.degree++;
		displayPolynomial(poly1);
	}
	
	poly2 = copyPolynomial(poly1);
	printf("\n[copied poly2]\n");
	displayPolynomial(poly2);
	
	printf("\n[poly1 + poly2]\n");
	ret = addPolynomial(poly1, poly2);
	displayPolynomial(ret);
	deletePolynomial(ret);
	
	ret = subPolynomial(poly1, poly2);	
	printf("\n[poly1 - poly2]\n");
	displayPolynomial(ret);
	deletePolynomial(ret);
	ret = mulPolynomial(poly1, poly2);
	printf("\n[poly1 * poly2]\n");
	displayPolynomial(ret);
	deletePolynomial(ret);

	for (int i = 2; i < 5; i++)
	{
		ret = powerPolynomial(poly1, i);
		printf("\n[poly1^%d]\n", i);
		displayPolynomial(ret);
		deletePolynomial(ret);
	}
	
	deletePolynomial(poly1);
	deletePolynomial(poly2);

	return (0);
}


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

