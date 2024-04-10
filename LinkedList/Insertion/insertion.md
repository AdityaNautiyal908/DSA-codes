# Insertion in Linked List

Given a Linked List, the task is to insert a new node at various positions:

1. At the front of the linked list.
2. After a given node.
3. At the end of the linked list.

## Insertion at the Front/Beginning of Linked List

### Approach

To insert a node at the start/beginning/front of a Linked List, we need to:

1. Make the first node of the Linked List linked to the new node.
2. Remove the head from the original first node of the Linked List.
3. Make the new node as the Head of the Linked List.

<img width="500px" src="https://media.geeksforgeeks.org/wp-content/uploads/     20240222162726/Insertion-at-the-Beginning-of-Singly-Linked-List.webp" alt="">

# How to Insert a Node at a Specific Position in Linked List

## Approach

To insert a node at a specific position in a Linked List, follow these steps:

1. Check if the given node exists or not.
    - If the given node does not exist, terminate the process.
    - If the given node exists, proceed to the next step.

2. Make the element to be inserted as a new node.

3. Change the next pointer of the given node to the new node.

4. Shift the original next pointer of the given node to the next pointer of the new node.

<img width="500px" src="https://media.geeksforgeeks.org/wp-content/uploads/20240222162809/Insertion-at-a-Specific-Position-of-the-Singly-Linked-List.webp" alt="">

# How to Insert a Node at the End of Linked List

## Approach

To insert a node at the end of a Linked List, follow these steps:

1. Go to the last node of the Linked List.

2. Change the next pointer of the last node from NULL to the new node.

3. Make the next pointer of the new node as NULL to signify the end of the Linked List.


<img width="500px" src="https://media.geeksforgeeks.org/wp-content/uploads/20240222162837/Insertion-at-the-End-of-Singly-Linked-List.webp" alt="">

