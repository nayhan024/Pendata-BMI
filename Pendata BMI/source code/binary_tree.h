struct root {
    int key;
    struct root *left, *right;
};
 
// A utility function to create a new BST root
struct root* newNode(int item)
{
    struct root* temp
        = (struct root*)malloc(sizeof(struct root));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
void inorder(struct root* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
 
/* A utility function to
   insert a new root with given key in
 * BST */
struct root* insert(struct root* root, int key)
{
    /* If the tree is empty, return a new root */
    if (root == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
 
    /* return the (unchanged) root pointer */
    return root;
}

struct root* search_binary(struct root* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search_binary(root->right, key);
 
    // Key is smaller than root's key
    return search_binary(root->left, key);
}

// Driver Code
void binary_tree()
{
	char *filename = "bmi.txt";
    char *filename1 = "nama.txt";
	
    // open the file for reading
    FILE *fa;
	fa = fopen(filename1, "r"); 	
    if (fa == NULL){
        printf("Error opening the file %s", filename);
    }
    
	FILE *fb;
    fb = fopen(filename, "r");
    if (fb == NULL){
        printf("Error opening the file %s", filename);
    }
	
    // read the text file
    char text[100] = {'\0'};
    int i=0;
    
	int temp[100];
    char temp1[100][10] = {'\0'};
    
    while (fscanf(fb, "%s", text) == 1){
		temp[i] = atoi(text);
		fscanf(fa, "%s", temp1[i]);
		i++;
    }
    
    //close file
    fclose(fa);
	fclose(fb);
	
	//insert
    struct root* root = NULL;
    struct root* iteratorPtr = NULL;
    
    int size = i;
    
    for(i=0;i<size;i++){
    	root = insert(root, temp[i]);
	}
 	
    printf("Binary Tree \n\n");
    inorder(root);
 	
 	//search_binary
 	int input;
 	printf("\n\nInput BMI yang ingin dicari : ");
 	input = getIntegerOnly();
 	iteratorPtr = search_binary(root, input);
 	
 	if(iteratorPtr == NULL){
 		printf("\nTidak ada");
	}
 	else{
 		printf("\nDitemukan");
 		printf("\nAddress : %d", iteratorPtr);
 		printf("\nValue : %d", (*iteratorPtr).key);
	}
	
 	printf("\n\n");
    system("pause");
    
}
