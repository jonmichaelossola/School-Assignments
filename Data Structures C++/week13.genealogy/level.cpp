void BNode::level()
{
  const int MAX = 100;
  BNode *queue[MAX];
  BNode *temp;
  int front = 0;
  int back = 0;

  queue[back++] = this;

  while (front != back)
  {
    temp = queue[front];
    front = (front + 1) % MAX;
    if (temp != NULL)
    {
      // visit
      cout.width(4);
      cout << temp->data << " ";
      // end Visit        
      queue[back] = temp->left;
      back = (back + 1) % MAX;
      queue[back] = temp->right;
      back = (back + 1) % MAX;

    }
  }
}
