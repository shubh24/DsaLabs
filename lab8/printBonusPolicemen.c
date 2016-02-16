#include "PoliceTreeOps.h"


void printBonusPolicemen(PoliceTree root,int MaxAmount)
{
	
		PoliceTree p,q;
		
		p=root;
		if(p==NULL)
		{
			return;
		}
		printBonusPolicemen(p->left,MaxAmount);

		if ( p->amount >= 0.9*MaxAmount )			
			fprintf(stderr, "%u: %d,%d ==> %u| <%u >%u\n",
		    	p,  p->id, p->amount, p->succ, p->left, p->right);

		printBonusPolicemen(p->right,MaxAmount);
		
		return;

}
