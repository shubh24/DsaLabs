#include "PoliceTreeOps.h"


static inline PoliceTree createTreeNode(PoliceId id, int amount)
{
		PoliceTree new = (PoliceTree) malloc(sizeof(PoliceTreeNode));
		if(new == NULL)
		{
				fprintf(stderr, "\nOut of memory while inserting in in_BST\n");
				exit(-1);
		}

		new->succ=NULL;
		new->left=NULL;
		new->right = NULL;
		new->amount = amount;
		new->id=id;
		return new;

}


static inline PoliceTree insertByFine(PoliceTree root, PoliceId id, int amount)
{
	
	
	PoliceTree p, prev, succ;
	p=prev=succ = NULL;

	if ( root == NULL ){
		PoliceTree new=createTreeNode(id, amount);
		return new;
	}

	p = root;
	
	while ( p != NULL ){
	if(amount <= p->amount ) // search left tree
		{
				succ = p;
				if (p->left == NULL)
				{
						PoliceTree new= createTreeNode(id, amount);
						p->left = new;
//						new->succ = succ;
						if(prev != NULL)
						{
								new->succ = prev->succ;
								prev->succ = new;
						}
						else
								new->succ=succ;
						return root;
				}
				p=p-> left;
		}
	else if(amount > p->amount) // search right tree
		{
				prev=p;
				if (p->right== NULL)
				{
						PoliceTree new= createTreeNode(id, amount);
						p->right = new;
						if(prev != NULL)
						{
								new->succ = prev->succ;
								prev->succ = new;
						}
						else
								new->succ=succ;

/*
						new->succ = prev->succ;
						prev->succ = new;
*/
						return root;
				}
				p=p->right;
		}
	}
	return root;
}

PoliceTree reorderByFineAmount(PoliceTree root)
{

	PoliceTree p = root;
	
	PoliceTree ans = NULL;

	
	//printf("%d\n",rightMost->succ->id);

	p = root;

	while(p->left !=NULL){
		p=p->left;
	}

	//printf("%d\n",p->succ->id);


	ans = insertByFine(ans,p->id,p->amount);

	while ( p->succ != NULL ){
		
		p = p->succ;
		ans = insertByFine(ans,p->id,p->amount);
	}

	return ans;

}
