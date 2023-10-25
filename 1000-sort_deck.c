#include "deck.h"

int compareSTR(const char *str1, const char *str2);
char valGET(deck_node_t *card);
void ins_sr_DECkind(deck_node_t **deck);
void ins_sr_DECval(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * compareSTR - this function compare between tow str.
 * @str1: str num one.
 * @str2: str num tow.
 * Return: posi byte or 0 or nega byte
 */
int compareSTR(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * valGET - function to get the val of card varibale.
 * @card: pointer to head of linked list.
 * Return: return char.
 */
char valGET(deck_node_t *card)
{
	if (compareSTR(card->card->value, "Ace") == 0)
		return (0);
	if (compareSTR(card->card->value, "1") == 0)
		return (1);
	if (compareSTR(card->card->value, "2") == 0)
		return (2);
	if (compareSTR(card->card->value, "3") == 0)
		return (3);
	if (compareSTR(card->card->value, "4") == 0)
		return (4);
	if (compareSTR(card->card->value, "5") == 0)
		return (5);
	if (compareSTR(card->card->value, "6") == 0)
		return (6);
	if (compareSTR(card->card->value, "7") == 0)
		return (7);
	if (compareSTR(card->card->value, "8") == 0)
		return (8);
	if (compareSTR(card->card->value, "9") == 0)
		return (9);
	if (compareSTR(card->card->value, "10") == 0)
		return (10);
	if (compareSTR(card->card->value, "Jack") == 0)
		return (11);
	if (compareSTR(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * ins_sr_DECkind - function to sort deck.
 * @deck: pointer to head of db linked ls.
 * Return: void
 */
void ins_sr_DECkind(deck_node_t **deck)
{
	deck_node_t *varIt, *isrt, *tpVar;

	for (varIt = (*deck)->next; varIt != NULL; varIt = tpVar)
	{
		tpVar = varIt->next;
		isrt = varIt->prev;
		while (isrt != NULL && isrt->card->kind > varIt->card->kind)
		{
			isrt->next = varIt->next;
			if (varIt->next != NULL)
				varIt->next->prev = isrt;
			varIt->prev = isrt->prev;
			varIt->next = isrt;
			if (isrt->prev != NULL)
				isrt->prev->next = varIt;
			else
				*deck = varIt;
			isrt->prev = varIt;
			isrt = varIt->prev;
		}
	}
}

/**
 * ins_sr_DECval - function to sort the deck.
 * @deck: pointer to head of db linked ls.
 * Return: void
 */
void ins_sr_DECval(deck_node_t **deck)
{
	deck_node_t *varIt, *isrt, *tpVar;

	for (varIt = (*deck)->next; varIt != NULL; varIt = tpVar)
	{
		tpVar = varIt->next;
		isrt = varIt->prev;
		while (isrt != NULL &&
		       isrt->card->kind == varIt->card->kind &&
		       valGET(isrt) > valGET(varIt))
		{
			isrt->next = varIt->next;
			if (varIt->next != NULL)
				varIt->next->prev = isrt;
			varIt->prev = isrt->prev;
			varIt->next = isrt;
			if (isrt->prev != NULL)
				isrt->prev->next = varIt;
			else
				*deck = varIt;
			isrt->prev = varIt;
			isrt = varIt->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: pointer to head of db linked ls.
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	ins_sr_DECkind(deck);
	ins_sr_DECval(deck);
}
