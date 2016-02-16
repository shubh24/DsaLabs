

typedef struct node{
	int cust_id;
	char item_id[9];
	int item_cost;
	struct node* next;
}node;

typedef struct Hash_id{
	node* ptr;
}Hash_id;
	

typedef struct Hash_item{
	node n;
	Hash_id* ptr_Hash_id;
}Hash_item;






