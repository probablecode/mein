#include "polynomial.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

Term	*addTerm(Term *t1, Term *t2)
{
	Term	*result = NULL;
	int		add;


	add = (t1 -> data).coefficient + (t2 -> data).coefficient;
	if (add)
	{
		result = (Term *)malloc(sizeof(Term));
		if (result)
		{
			(result -> data).coefficient = add;
			(result -> data).degree = (t1 -> data).degree;
			result -> pLink = NULL;
		}
	}
	return (result);
}

Term	*mulTerm(Term *t1, Term *t2)
{
	Term	*result = NULL;
	int		mul;


	mul = (t1 -> data).coefficient * (t2 -> data).coefficient;
	result = (Term *)malloc(sizeof(Term));
	if (result)
	{
		(result -> data).coefficient = mul;
		(result -> data).degree = (t1 -> data).degree + (t2 -> data).degree;
		result -> pLink = NULL;
	}
	return (result);
}

Polynomial	*createPolynomial()
{
	Polynomial	*pPoly;

	pPoly = (Polynomial *)malloc(sizeof(Polynomial));
	if (pPoly)
	{
		pPoly -> currentElementCount = 0;
		(pPoly -> headerNode).pLink = NULL;
	}
	return (pPoly);
}

/*
띠용..? 이 함수는 뭐지
Monomial newMonomial(int degree, int coefficient)
{
	Monomail ret;
	
	ret.degree = degree;
	ret.coefficient = coefficient;
	return (ret);
}
*/
void deleteTerm(Term *term)
{
	if (term)
	{
			(term -> data).degree = 0;
			term -> pLink = NULL;
			free (term);
	}
}


void clearPolynomial(Polynomial* pPoly)
{
	Term	*tmp;
	Term	*next;

	if (pPoly)
	{
		next = (pPoly -> headerNode).pLink;
		while (next)
		{
			tmp = next -> pLink;
			(next -> data).coefficient = 0;
			deleteTerm(next);
			next = tmp;
		}
		(pPoly -> headerNode).pLink = NULL;
		pPoly -> currentElementCount = 0;
	}
 }

void deletePolynomial(Polynomial* pPoly)
{
	if (pPoly)
	{
		clearPolynomial(pPoly);
		free(pPoly);
	}
}


int	getPolynomialLength(Polynomial* pPoly)
{
	if (pPoly)
		return (pPoly -> currentElementCount);
	else
		return (ERROR);
}

Polynomial	*copyPolynomial(Polynomial *pPoly)
{
	Polynomial	*new = NULL;
	Term		*dst;
	Term		*tmp;
	Term		*copy;

	if (pPoly)
	{
		new = (Polynomial *)malloc(sizeof(Polynomial));
		if (new)
		{
			dst = &(new -> headerNode);
			tmp = (pPoly -> headerNode).pLink;
			while (tmp)
			{
				copy = (Term *)malloc(sizeof(Term));
				if (copy)
					copy -> data = tmp -> data;// stop은 생각하지 않겠다.
				copy -> pLink = NULL;
				dst -> pLink = copy;
				dst = copy;
				tmp = tmp -> pLink;
			}
			new -> currentElementCount = pPoly -> currentElementCount;
		}
	}
	return (new);
}

int addPElement(Polynomial* pPoly, Monomial element)
{
	Term	*new;
	Term	*pre = NULL;
	Term	*next;
	int		ret = ERROR;
	int		degree = element.degree;
	if (pPoly)
	{
		ret = FALSE;
		if (0 <= degree && element.coefficient)
		{
			ret = TRUE;
			next = (pPoly -> headerNode).pLink;
			while (next)
			{
				if ((next -> data).degree <= degree)
					break;
				pre = next;
				next = next -> pLink;
			}
			if (!pre) // 하나있으면 같거나, 새노드가 더 큼 , 하나도없으면
			{
				if (next && degree == (next -> data).degree)
				{
					if (!((next -> data).coefficient += element.coefficient))
					{
						(pPoly -> headerNode).pLink = next -> pLink;
						deleteTerm(next);
						pPoly -> currentElementCount--;
					}
				}
				else
				{
					new = (Term *)malloc(sizeof(Term));
					if (new)
					{
						new -> data  = element;
						if (next)
							new -> pLink = next;
						pPoly -> currentElementCount++;
					}
					(pPoly -> headerNode).pLink = new;
				}
			}
			else
			{

				if (next && degree == (next -> data).degree)
				{
					if (!((next -> data).coefficient += element.coefficient))
					{
						pre -> pLink = next -> pLink;
						deleteTerm(next);
						pPoly -> currentElementCount--;
					}
				}
				else
				{
					new = (Term *)malloc(sizeof(Term));
					if (new)
					{
						new -> data = element;
						pre -> pLink = new;
						new -> pLink = next;
						pPoly -> currentElementCount++;
					}
				}
			}
		}
	}
	return (ret);
}

void printSuperScript(int i)
{
	static char *str[10] = {"\u2070", "\u00B9", "\u00B2", "\u00B3"
	, "\u2074" ,"\u2075" ,"\u2076", "\u2077", "\u2078", "\u2079"};
	write(1, str[i], 3);
}


void displayMonomial(Monomial data)
{	
	int	number = data.coefficient;
	int	digit[10];
	char c[11];
	int i = 9;
	
		c[10] = 'x' * (data.degree != 0);
	number *= ((0 < number) - (number < 0));	
	while (number)
	{
		c[i--] = '0' + number % 10;
		number /= 10;
	}
	write (1, c + (i + 1), 10 - i);
	i = 0;
	number = data.degree;
	while (number)
	{
		digit[i++] = number % 10;
		number /= 10;
	}
	while (0 < i--)
		printSuperScript(digit[i]);
}

void displayPolynomial(Polynomial *pPoly)
{
	Term	*term;
	int		sign;
	if (pPoly)
	{
		term = (pPoly -> headerNode).pLink;
		if (term)
		{
			if ((term -> data).coefficient < 0)
				write(1, "-", 1);
			displayMonomial(term -> data);
			term = term -> pLink;
			while (term)
			{
				if (0 < (term -> data).coefficient)
					write(1, " + ", 3);
				else
					write(1, " - ", 3);
				displayMonomial(term -> data);
				term = term -> pLink;
			}
		}
		else
			printf("[Empty Polynomial]");
		printf("\n");
	}
}

Polynomial	*addPolynomial(Polynomial *pPoly1, Polynomial *pPoly2)
{
	Polynomial	*result = NULL;
	Term	*tmp;

	if (pPoly1 && pPoly2)
	{
		result = copyPolynomial(pPoly1);
		tmp = (pPoly2 -> headerNode).pLink;
		while (tmp)
		{
			addPElement(result, tmp -> data);
			tmp = tmp -> pLink;
		}
	}
	return (result);
}

 
Polynomial	*mulMonomial(Polynomial	*pPoly, Monomial element)
{
	Polynomial	*result = NULL;
	Term	*tmp;

	if (pPoly && element.coefficient)
	{
		result = copyPolynomial(pPoly);
		tmp = (result -> headerNode).pLink;
		while (tmp)
		{
			(tmp -> data).degree += element.degree;
			(tmp -> data).coefficient *= element.coefficient;
			tmp = tmp -> pLink;
		}
	}
	return (result);
}

Polynomial	*mulPolynomial(Polynomial *pPoly1, Polynomial *pPoly2)
{
	Polynomial	*result = NULL;
	Polynomial	*addP;
	Polynomial	*tmpP;
	Term		*tmpT;

	if (pPoly1 && pPoly2)
	{
		tmpT = (pPoly2 -> headerNode).pLink;
		if (tmpT)
		{
			result = mulMonomial(pPoly1, tmpT -> data);
			tmpT = tmpT -> pLink;
			while (tmpT)
			{
				tmpP = addPolynomial(result, addP = mulMonomial(pPoly1, tmpT -> data));
				deletePolynomial(addP);
				deletePolynomial(result);
				result = tmpP;
				tmpT = tmpT -> pLink;
			}
		}
	}
	return (result);
}

Polynomial	*subPolynomial(Polynomial *pPoly1, Polynomial *pPoly2)
{
	Polynomial	*result = NULL;
	Polynomial	*tmpP;
	Monomial	minus;
	
	if (pPoly1 && pPoly2)
	{
		tmpP = copyPolynomial(pPoly2);
		if (tmpP)
		{
			minus.degree = 0; minus.coefficient = -1;
			result = mulMonomial(tmpP, minus);
			deletePolynomial(tmpP);
			tmpP = result;
			result = addPolynomial(pPoly1, tmpP);
			deletePolynomial(tmpP);
		}
	}
	return (result);
}


Polynomial	*powerPolynomial(Polynomial *pPoly, int power)
{
	Polynomial	*result;
	Polynomial	*tmp;

	result = copyPolynomial(pPoly);
	for (int i = 1; i < power; i++)
	{
		tmp = mulPolynomial(result, pPoly);
		deletePolynomial(result);
		result = tmp;
	}
	return (result);
}

/*
// final boss
Polynomial	*divPolynomial(Polynomial *dividend, Polynomial *divisor, Polynomial **remainder)
{
	Polynomial	*quotient;
	Polynomial	*div;
	Term		*Term;
	int			divDegree;

	if (dividend && divisor)
	{
		tmp = ((div = copyPolynomial(dividend)) -> headerNode).pLink;
		divDegree = ((divisor -> headerNode).pLink -> data).degree;
		
		while ((tmp -> data).degree > divDegree)
		{
		}

	}
	return (quotient);
}*/
