Dạng 3: 

void quickSort(int a[], int l, int r) //Sap xep day khong giam
{
    int p = a[(l + r) / 2];
    int i = l, j = r;
    while (i < j)
    {
        while (a[i] < p)
        {
            i++;
        }
        while (a[j] > p)
        {
            j--;
        }
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r)
    {
        quickSort(a, i, r);
    }
    if (l < j)
    {
        quickSort(a, l, j);
    }
}



void InsertionSort(int a[], int n){	
	int pos, key;
	for(int i = 1; i < n; i++){ //đoạn a[0] đã sắp
		key= a[i]; 
		pos = i;
		while(pos > 0 && key < a[pos-1]){
			a[pos] = a[pos-1];	// dời chỗ của phần tử lớn lên 1 đơn vị 
			pos--;
		}
		a[pos] = key;
	}
}




void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b= temp;
}
void selectionSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if (a[minIndex]>a[j]){
                minIndex= j;
            }
        }
        if (i!= minIndex){
            swap(&a[i], &a[minIndex]);
        }
    }
}




void bubbleSort(int a[], int n)     //Optimized bubbleSort vs noSwapvariable
{
    for (int i = n - 1; i >= 1; i--)
    {
        bool noSwap = true;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            { //sort ascending
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                noSwap = false;
            }
        }
        if (noSwap)
        {
            break;
        }
    }
}






int LinearSearch(int arr[], int numberOfElements, int key)
{
    for (int i = 0; i < numberOfElements; i++)
        if (arr[i] == key)
            return i;
    return -1;
}





int Binary_search (int a[], int n, int x )
{
    int l = 0, r = n-1;
        while(r >= l)
        {
            int mid =(l + r)/2;
            if(a[mid] == x)
                return mid;   
            else if(a[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;          
        }
        if (l == r && a[l] != x)
            return -1;  // không tìm thấy x
}




Dạng 4: 


Stack :


typedef struct Node
{
    int data;
    struct Node *next;
} node;
 
node *top;	// pointer to the top of the stack 
 
void pop()
{
    node *temp;
    if (top==NULL){
        printf("\nStack underflow\n");
        exit(1);
    }
    else{
        // top is assigned into temp
        temp = top;
        //assign second node to top
        top= top->next;
        // Destroy connection between first and second
        temp->next= NULL;
        // Release memory of the old top node
        free(temp);
    }
}

void push(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if (!temp)
    {
        printf("\nHeap Overflow");
        exit(1);
    }
    // insert a new node to the top of the stack 
    temp->data = data;
    temp->next = top;
    top = temp;
}

int isEmpty()
{
    return top == NULL;
}


int peek()
{
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}




Queue:


#define full 13
typedef int datatype;
 
typedef struct node
{
    datatype data;
    struct node *next;
} node;
 
typedef struct queue
{
    int count;
    node *front;
    node *rear;
} queue;
 

datatype dequeue (queue *q){
    node *tmp = q->front;   //point the temp node to the front one of the queue
    datatype n = tmp->data;
    q->front = tmp->next;   //point the front to the node next to the current front node 
    q->count--;
    free(tmp);
    return n;
}

void enqueue(queue *q, datatype value)
{
    if(q->count<full){
        node *tmp = (node *)malloc(sizeof(node));
        tmp->data=  value;
        tmp->next = NULL;
        if (isEmpty(q)){
            q->front = q->rear = tmp;   //Queue is empty--> tro ca node dau va node cuoi vao tmp 
        }
        else{
            q->rear->next = tmp;    // cho node cuoi tro vao tmp
            q->rear = tmp;          // Gan tmp = node cuoi cua queue
        }
        q->count++;
    }
}




Ứng dụng: Chuyển đổi hệ cơ số 



void chuyenCoSo(int decNumber, int newbase){
    while(decNumber!=0){
        int remain = decNumber%newbase;
        //add x to stack 
        push(remain);
        // continue to divide 
        decNumber/=newbase;
    }
}
void display_newbased_number(){
    printf("\n");
    while(!isEmpty()){
        if(peek()<10){
            printf("%d", peek());
            pop();
        }
        else{
            printf("%c", peek()+55 );
            pop();
        }
    }
}





DẠNG 5:


typedef int datatype;
 
typedef struct node
{
  datatype key;
  struct node *left, *right;
} node;
 

// Create a node
node *newNode(datatype item)
{
  node *temp = (node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
 
void inorderTraverse(node *root)
{
  if (root != NULL)
  {
    inorderTraverse(root->left);
    printf("%d  ", root->key);
    inorderTraverse(root->right);
  }
}
 

node *insert(node *newnode, datatype key)
{
  // Return a new node if the tree is empty
  if (newnode == NULL)
    return newNode(key);
 
  // Traverse to the right place and insert the node
  if (key < newnode->key)
    newnode->left = insert(newnode->left, key);
  else
    newnode->right = insert(newnode->right, key);
 
  return newnode;
}


 
// Find the inorder successor/inheritor
node *minValueNode(node *Node)
{
  node *current = Node;
 
  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;
 
  return current;
}
// Deleting a node
node *deleteNode(node *root, int key)
{
  // Return if the tree is empty
  if (root == NULL)
    return root;
 
  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else
  {
    // If the node is with only one child or no child
    if (root->left == NULL)
    {
      node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      node *temp = root->left;
      free(root);
      return temp;
    }
 
    // If the node has two children
    node *temp = minValueNode(root->right);
 
    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;
 
    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
 
node *SearchNode(node *root, int key)
{
  if (root == NULL)
  {
    return NULL;
  }
  else
  {
    if (key < root->key)
    {
      SearchNode(root->left, key);
    }
    else if (key > root->key)
    {
      SearchNode(root->right, key);
    }
    else
    {
      return root;
    }
  }
}
