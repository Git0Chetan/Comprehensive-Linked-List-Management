#include<iostream>
#include<vector>
using namespace std;

class node{
  public:
  int data;
  node* next;
};

void insertion(node** head);
void deletion(node** head);
void reverse(node** head);
void sort(node** head);
void check_palindrome(node* head);
int count(node* head);
void search(node* head);
void find_middle(node* head);
void display(node* head);


int main(){
    
    node* head=NULL;
    
    int end=0;
    do{
    cout<<"\nwhich operation do you want to perfom on given singly linked list";
    cout<<"\n1.insertion \t2.deletion \t3.reverse \n4.sorting \t5.check_palindrome \t6.count \n7.search \t8.find middle \t9.display \n10.end"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
        insertion(&head);
        break;
        
        case 2:
        deletion(&head);
        break;
        
        case 3:
        reverse(&head);
        break;
        
        case 4:
        sort(&head);
        break;
        
        case 5:
        check_palindrome(head);
        break;
        
        case 6:
        cout<<"elements in LL are: "<<count(head);
        break;
        
        case 7:
        search(head);
        break;
        
        case 8:
        find_middle(head);
        break;
        
        case 9:
        display(head);
        break;
        
        case 10:
        end=1;
        break;
        
        default:
        cout<<"entered wrong option"<<endl;
    }
    }while(end!=1);
    
}


void insertion(node**head){
    cout<<"\n where do you to insert the element in the list";
    cout<<"\n 1.at beginning\t 2.at end \t 3.at position"<<endl;
    int c1;
    int cc1;
    cin>>c1;
    if(c1==3){
        cout<<"which position do u want:";
        cin>>cc1;
        c1=cc1;
    }
    cout<<"enter the data\n";
    int data;
    cin>>data;
    
    if(c1==1){
        node* newnode=new node();
        newnode->data=data;
        
        if(*head==NULL){
            newnode->next=NULL;
            *head=newnode;
            return;
        }
        else{
           newnode->next=*head;
           *head=newnode;
           return;
        }
    }
    
    if(c1==2){
        node* newnode=new node();
        newnode->data=data;
        newnode->next=NULL;
        
        if(*head==NULL){
            *head=newnode;
            return;
        }
        else{
            node* temp=*head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            return;
        }
        
    }
    if(c1==3){
        int size=count(*head);
        node* newnode=new node();
        newnode->data=data;
        

        if(cc1<1 || cc1>size){
            cout<<"Enter a valid position"<<endl;
            return;
        }
        if(cc1==1){
            if(*head==NULL){
            *head=newnode;
            newnode->next=NULL;
            return;
            }
            else{
                newnode->next=*head;
                *head=newnode;
            }
        }
        else{
            node* temp=*head;
            for(int i=cc1-2;i>0;i--){
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}


void deletion(node** head){
    cout<<"\n from where do you to delete the element in the list";
    cout<<"\n 1.from beginning\t 2.from end \t 3.at position"<<endl;
    int c1;
    int cc1;
    cin>>c1;
    if(c1==3){
        cout<<"which position do u want:";
        cin>>cc1;
        c1=cc1;
    }
    
    if(c1==1){
        if(*head==NULL){
            cout<<"LL is alredy empty";
            return;
        }else{
            node*temp=*head;
            *head=(*head)->next;
            free(temp);
        }
    }
    
    if(c1==2){
        if(*head==NULL){
            cout<<"LL is alredy empty";
            return;
        }
        else if((*head)->next==NULL){
            node*temp=*head;
            *head=NULL;
        }
        else{
            node* temp=*head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            free(temp->next);
            temp->next=NULL;
        }
    }
    
    if(c1==3){
        int size=count(*head);
        if(cc1<1 || cc1>size){
            cout<<"Enter a valid position"<<endl;
            return;
        }
        if(cc1==1){
            node*temp=*head;
            *head=(*head)->next;
            free(temp);
        }
        else{
            node* prev=*head;
            cc1=cc1-2;
            while(cc1>0){
                prev=prev->next;
                cc1--;
            }
            node*temp;
            temp=prev->next;
            prev->next=temp->next;
            free(temp);
        }
    }
}



void reverse(node** head){
    node* temp=*head;
    if(*head==NULL){
        cout<<"LInked list is empty:";
        return;
    }
    vector<int>v1;
    int size=count(temp);
    
    while(temp!=NULL){
        int a=temp->data;
        v1.push_back(a);
        temp=temp->next;
    }
    
    node* temp1=*head;
    while(size!=0){
        int b=v1.at(size-1);
        temp1->data=b;
        temp1=temp1->next;
        size--;
    }
    
    cout<<"your reverse linked list operation is successful"<<endl;
}


void sort(node** head){
    node* headmain=*head;
    if(*head==NULL){
        cout<<"the linked list is empty";
        return;
    }
    
    while(headmain->next != NULL){
        int min= headmain->data;
        node* current=headmain->next;
        while(current != NULL){
            if(min > current->data){
                min=current->data;
                current->data=headmain->data;
                headmain->data=min;
            }
            current=current->next;
        }
        headmain=headmain->next;
    }
    cout<<"Linked list sorting is successfull"<<endl;
}


void check_palindrome(node* head){
    node* temp=head;
    bool flag=1;
    if(head==NULL){
        cout<<"LInked list is empty:";
        return;
    }
    vector<int>v1;
    // int size=count(temp);
    
    while(temp!=NULL){
        int a=temp->data;
        v1.push_back(a);
        temp=temp->next;
    }
    node * current= head;
    int size=v1.size();
    while(size!=0){
        int d=v1.at(size-1);
        if(current->data!=d){
            flag=0;
            break;
        }
        current=current->next;
        size--;
    }

    if(flag==1){
        cout<<"it is a palindrome:"<<endl;
    }else{
        cout<<"sorry, it is not a palindrome"<<endl;
    }

}


int count(node* head){
    int size=0;
    if(head==NULL){
        return 0;
    }
    else{
        node* temp=head;
        while(temp != NULL){
            size++;
            temp=temp->next;
        }
    }
    return size;
}


void search(node* head){
    cout<<"which element do you want to search in the link list:"<<endl;
    int find;
    int index=0;
    int found=1;
    cin>>find;
    
    if(head==NULL){
        cout<<"Linked list is empty:";
        return;
    }
    
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==find){
            found=0;
            break;
        }
        index++;
        temp=temp->next;
    }
    
    if(found==0){
        cout<<"we found element at index:"<<index<<endl;
    }else{
        cout<<"sorry, element is not present in the list"<<endl;
    }
    
}


void find_middle(node* head){
    int size=count(head);
    int mid;
    int index=0;
    if(head==NULL){
        cout<<"LL is empty:"<<endl;
        return;
    }
    else if(head->next==NULL){
        cout<<head->data<<" index: "<<index;
        return;
    }else{
        if(size%2==0){
            mid=size/2;
        }else{
            mid=(size+1)/2;
        }
    }
    
    node* temp=head;
    while(mid!=1){
        temp=temp->next;
        index++;
        mid--;
    }
    
    cout<<temp->data<<" index : "<<index<<endl;
}


void display(node* head){
    if(head==NULL){
        cout<<"list is empty";
        return;
    }
    else{
        node* temp=head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
        return;
    }
}