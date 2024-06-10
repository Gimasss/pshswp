/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:23:14 by gmastroc          #+#    #+#             */
/*   Updated: 2024/06/10 14:40:59 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


void addNodeToTail(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode
        newNode->prev = current;
    }
}

void addNodeToHead(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

Node* getTail(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

Node* getNodeWithMaxValue(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* maxNode = head;
    while (head != NULL) {
        if (head->value > maxNode->value) {
            maxNode = head;
        }
        head = head->next;
    }
    return maxNode;
}

Node* getNodeWithMinValue(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* minNode = head;
    while (head != NULL) {
        if (head->value < minNode->value) {
            minNode = head;
        }
        head = head->next;
    }
    return minNode;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    addNodeToTail(&head, 10);
    addNodeToTail(&head, 20);
    addNodeToTail(&head, 30);
    addNodeToHead(&head, 5);

    printList(head);

    Node* tail = getTail(head);
    if (tail != NULL) {
        printf("Tail value: %d\n", tail->value);
    }

    Node* maxNode = getNodeWithMaxValue(head);
    if (maxNode != NULL) {
        printf("Node with max value: %d\n", maxNode->value);
    }

    Node* minNode = getNodeWithMinValue(head);
    if (minNode != NULL) {
        printf("Node with min value: %d\n", minNode->value);
    }

    return 0;
}