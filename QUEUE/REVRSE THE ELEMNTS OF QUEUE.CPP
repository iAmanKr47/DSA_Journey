//RECURSIVE STACK WOULD BE CREATED | PUSH THE ELEMENT IN THE QUEUE WHILE RETURNING FROM THE RECURSSIVE CALL.

void rev(queue<int>&q,int k){
    if(k==0)
    return ;
    int val=q.front();
    q.pop();
    rev(q,k-1);
    q.push(val);
    
}
