## Reverse K nodes , if K not left leave as it is.

Lets say I have a Liked list `1->2->3->4->5->6->7.`
and **K**=3.

The the resulting LL will be `3->2->1->6->5->4->7`.

### First Approach.
- Keep reversing the linked list until the k nodes are covered all a null is reached.
- This will make a discontinuous linked list.
- `3->2->1 6->5->4 7`

//To be done.