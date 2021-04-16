typedef struct NODE
{
	int reg_no;
	int age;
	char name[20];
	struct NODE *next;
} node;

node* deq();
int create();
int reserve(node*);
int cancel(int);
void enq(node*);
void display();


node *start;
node *front;
node *rear;
int count=0;
int num=0;

int create( )
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->reg_no=1;
	printf("Name: ");
	scanf("%s", new->name);
	printf("Age : ");
	scanf("%d", &new->age);
    if(new->age>=90 || new->age<=10) {
        free(new);
        return -1;
    }
	
	start=new;
	new->next=NULL;
	num++;
    return 1;
	
}

int reserve(node *start)
{
	int temp;
	if(start==NULL)
	{   
   		temp = create(start);
		 return temp;
	}
	else 
	{
	
	node *temp, *new_node;
	temp=start;
	while(temp->next!=NULL)
	{ 
	  temp=temp->next;
	}
	
	new_node=(node *)malloc(sizeof(node));
	
	printf("Name: ");
	scanf("%s", new_node->name);
	printf("Age : ");
	scanf("%d", &new_node->age);
    if(new_node->age >=90 || new_node->age<=10) {
        return -1;
    }
	new_node->next=NULL;
	if(num<=size)
	{
		num++;
		new_node->reg_no=num;
		temp->next=new_node;
		
		return 1;
	}
	else
	{
		enq(new_node);
		return 0;
	}
}
}


int cancel(int reg)
{
	node *ptr, *preptr, *new;
	ptr=start;
	preptr=NULL;
	if(start==NULL)
	return -1;
	if(ptr->next==NULL && ptr->reg_no==reg)
		{
		start=NULL;
		num--;
		free(ptr);
		return 1;
		
		}
		
	else{	
	while(ptr->reg_no!=reg && ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL && ptr->reg_no!=reg)
			return -1;
		else
			preptr->next=ptr->next;
		free(ptr);
		new=deq();
		while(preptr->next!=NULL)
			preptr=preptr->next;
		preptr->next=new;
		num--;
		return 1;
	
	}
}

void enq(node *new_node)
{
	if(rear==NULL)
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else
	{
		node *temp;
		temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	count++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    count-- ;
		if(front->next!=NULL)
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			
			return front1;
		}
	}	
}


void display()
{
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("\nTicket Number: %d\n", temp->reg_no);
		printf("Name : %s\n\n", temp->name);
		temp=temp->next;
    }
    
}
