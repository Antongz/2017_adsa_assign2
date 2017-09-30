#include <iostream>
#include <stdio.h>
#include <string.h>
#include<sstream>
#include <fstream>
#include <iomanip>
using namespace std;

template <class T>
class AVLTreeNode{
    public:
        T key;                // Ã¥â€¦Â³Ã©â€Â®Ã¥Â­â€”(Ã©â€Â®Ã¥â‚¬Â¼)
        int height;         // Ã©Â«ËœÃ¥ÂºÂ¦
        AVLTreeNode *left;    // Ã¥Â·Â¦Ã¥Â­Â©Ã¥Â­Â
        AVLTreeNode *right;    // Ã¥ÂÂ³Ã¥Â­Â©Ã¥Â­Â

        AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r):
            key(value), height(0),left(l),right(r) {}
};

template <class T>
class AVLTree {
    private:
        AVLTreeNode<T> *mRoot;    // Ã¦ Â¹Ã§Â»â€œÃ§â€šÂ¹

    public:
        AVLTree();
        ~AVLTree();

        // Ã¨Å½Â·Ã¥Ââ€“Ã¦ â€˜Ã§Å¡â€žÃ©Â«ËœÃ¥ÂºÂ¦
        int height();
        // Ã¨Å½Â·Ã¥Ââ€“a,bÃ¤Â¸Â­Ã§Å¡â€žÃ¨Â¾Æ’Ã¥Â¤Â§Ã¥â‚¬Â¼
        int max(int a, int b);

        // Ã¥â€°ÂÃ¥ÂºÂÃ©ÂÂÃ¥Å½â€ "AVLÃ¦ â€˜"
        void preOrder();
        // Ã¤Â¸Â­Ã¥ÂºÂÃ©ÂÂÃ¥Å½â€ "AVLÃ¦ â€˜"
        void inOrder();
        // Ã¥ÂÅ½Ã¥ÂºÂÃ©ÂÂÃ¥Å½â€ "AVLÃ¦ â€˜"
        void postOrder();

        // (Ã©â‚¬â€™Ã¥Â½â€™Ã¥Â®Å¾Ã§Å½Â°)Ã¦Å¸Â¥Ã¦â€°Â¾"AVLÃ¦ â€˜"Ã¤Â¸Â­Ã©â€Â®Ã¥â‚¬Â¼Ã¤Â¸ÂºkeyÃ§Å¡â€žÃ¨Å â€šÃ§â€šÂ¹
        AVLTreeNode<T>* search(T key);

        // Ã¦Å¸Â¥Ã¦â€°Â¾Ã¦Å“â‚¬Ã¥Â°ÂÃ§Â»â€œÃ§â€šÂ¹Ã¯Â¼Å¡Ã¨Â¿â€Ã¥â€ºÅ¾Ã¦Å“â‚¬Ã¥Â°ÂÃ§Â»â€œÃ§â€šÂ¹Ã§Å¡â€žÃ©â€Â®Ã¥â‚¬Â¼Ã£â‚¬â€š
        T minimum();
        // Ã¦Å¸Â¥Ã¦â€°Â¾Ã¦Å“â‚¬Ã¥Â¤Â§Ã§Â»â€œÃ§â€šÂ¹Ã¯Â¼Å¡Ã¨Â¿â€Ã¥â€ºÅ¾Ã¦Å“â‚¬Ã¥Â¤Â§Ã§Â»â€œÃ§â€šÂ¹Ã§Å¡â€žÃ©â€Â®Ã¥â‚¬Â¼Ã£â‚¬â€š
        T maximum();

        // Ã¥Â°â€ Ã§Â»â€œÃ§â€šÂ¹(keyÃ¤Â¸ÂºÃ¨Å â€šÃ§â€šÂ¹Ã©â€Â®Ã¥â‚¬Â¼)Ã¦Ââ€™Ã¥â€¦Â¥Ã¥Ë†Â°AVLÃ¦ â€˜Ã¤Â¸Â­
        void insert(T key);

        // Ã¥Ë† Ã©â„¢Â¤Ã§Â»â€œÃ§â€šÂ¹(keyÃ¤Â¸ÂºÃ¨Å â€šÃ§â€šÂ¹Ã©â€Â®Ã¥â‚¬Â¼)
        void remove(T key);

        // Ã©â€â‚¬Ã¦Â¯ÂAVLÃ¦ â€˜
        void destroy();

    private:
        // Ã¨Å½Â·Ã¥Ââ€“Ã¦ â€˜Ã§Å¡â€žÃ©Â«ËœÃ¥ÂºÂ¦
        int height(AVLTreeNode<T>* tree) ;

        // Ã¥â€°ÂÃ¥ÂºÂÃ©ÂÂÃ¥Å½â€ "AVLÃ¦ â€˜"
        void preOrder(AVLTreeNode<T>* tree) const;
        // Ã¤Â¸Â­Ã¥ÂºÂÃ©ÂÂÃ¥Å½â€ "AVLÃ¦ â€˜"
        void inOrder(AVLTreeNode<T>* tree) const;
        // Ã¥ÂÅ½Ã¥ÂºÂÃ©ÂÂÃ¥Å½â€ "AVLÃ¦ â€˜"
        void postOrder(AVLTreeNode<T>* tree) const;

        // (Ã©â‚¬â€™Ã¥Â½â€™Ã¥Â®Å¾Ã§Å½Â°)Ã¦Å¸Â¥Ã¦â€°Â¾"AVLÃ¦ â€˜x"Ã¤Â¸Â­Ã©â€Â®Ã¥â‚¬Â¼Ã¤Â¸ÂºkeyÃ§Å¡â€žÃ¨Å â€šÃ§â€šÂ¹
        AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key) const;

        // Ã¦Å¸Â¥Ã¦â€°Â¾Ã¦Å“â‚¬Ã¥Â°ÂÃ§Â»â€œÃ§â€šÂ¹Ã¯Â¼Å¡Ã¨Â¿â€Ã¥â€ºÅ¾treeÃ¤Â¸ÂºÃ¦ Â¹Ã§Â»â€œÃ§â€šÂ¹Ã§Å¡â€žAVLÃ¦ â€˜Ã§Å¡â€žÃ¦Å“â‚¬Ã¥Â°ÂÃ§Â»â€œÃ§â€šÂ¹Ã£â‚¬â€š
        AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);
        // Ã¦Å¸Â¥Ã¦â€°Â¾Ã¦Å“â‚¬Ã¥Â¤Â§Ã§Â»â€œÃ§â€šÂ¹Ã¯Â¼Å¡Ã¨Â¿â€Ã¥â€ºÅ¾treeÃ¤Â¸ÂºÃ¦ Â¹Ã§Â»â€œÃ§â€šÂ¹Ã§Å¡â€žAVLÃ¦ â€˜Ã§Å¡â€žÃ¦Å“â‚¬Ã¥Â¤Â§Ã§Â»â€œÃ§â€šÂ¹Ã£â‚¬â€š
        AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

        // LLÃ¯Â¼Å¡Ã¥Â·Â¦Ã¥Â·Â¦Ã¥Â¯Â¹Ã¥Âºâ€Ã§Å¡â€žÃ¦Æ’â€¦Ã¥â€ Âµ(Ã¥Â·Â¦Ã¥Ââ€¢Ã¦â€”â€¹Ã¨Â½Â¬)Ã£â‚¬â€š
        AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);

        // RRÃ¯Â¼Å¡Ã¥ÂÂ³Ã¥ÂÂ³Ã¥Â¯Â¹Ã¥Âºâ€Ã§Å¡â€žÃ¦Æ’â€¦Ã¥â€ Âµ(Ã¥ÂÂ³Ã¥Ââ€¢Ã¦â€”â€¹Ã¨Â½Â¬)Ã£â‚¬â€š
        AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);

        // LRÃ¯Â¼Å¡Ã¥Â·Â¦Ã¥ÂÂ³Ã¥Â¯Â¹Ã¥Âºâ€Ã§Å¡â€žÃ¦Æ’â€¦Ã¥â€ Âµ(Ã¥Â·Â¦Ã¥ÂÅ’Ã¦â€”â€¹Ã¨Â½Â¬)Ã£â‚¬â€š
        AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);

        // RLÃ¯Â¼Å¡Ã¥ÂÂ³Ã¥Â·Â¦Ã¥Â¯Â¹Ã¥Âºâ€Ã§Å¡â€žÃ¦Æ’â€¦Ã¥â€ Âµ(Ã¥ÂÂ³Ã¥ÂÅ’Ã¦â€”â€¹Ã¨Â½Â¬)Ã£â‚¬â€š
        AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);

        // Ã¥Â°â€ Ã§Â»â€œÃ§â€šÂ¹(z)Ã¦Ââ€™Ã¥â€¦Â¥Ã¥Ë†Â°AVLÃ¦ â€˜(tree)Ã¤Â¸Â­
        AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T key);

        // Ã¥Ë† Ã©â„¢Â¤AVLÃ¦ â€˜(tree)Ã¤Â¸Â­Ã§Å¡â€žÃ§Â»â€œÃ§â€šÂ¹(z)Ã¯Â¼Å’Ã¥Â¹Â¶Ã¨Â¿â€Ã¥â€ºÅ¾Ã¨Â¢Â«Ã¥Ë† Ã©â„¢Â¤Ã§Å¡â€žÃ§Â»â€œÃ§â€šÂ¹
        AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z);

        // Ã©â€â‚¬Ã¦Â¯ÂAVLÃ¦ â€˜
        void destroy(AVLTreeNode<T>* &tree);

};

/*
 * Ã¦Å¾â€žÃ©â‚¬ Ã¥â€¡Â½Ã¦â€¢Â°
 */
template <class T>
AVLTree<T>::AVLTree():mRoot(NULL)
{
}

/*
 * Ã¦Å¾ÂÃ¦Å¾â€žÃ¥â€¡Â½Ã¦â€¢Â°
 */
template <class T>
AVLTree<T>::~AVLTree()
{
    destroy(mRoot);
}

/*
 * Ã¨Å½Â·Ã¥Ââ€“Ã¦ â€˜Ã§Å¡â€žÃ©Â«ËœÃ¥ÂºÂ¦
 */
template <class T>
int AVLTree<T>::height(AVLTreeNode<T>* tree)
{
    if (tree != NULL)
        return tree->height;

    return 0;
}

template <class T>
int AVLTree<T>::height()
{
    return height(mRoot);
}
/*
 * Ã¦Â¯â€Ã¨Â¾Æ’Ã¤Â¸Â¤Ã¤Â¸ÂªÃ¥â‚¬Â¼Ã§Å¡â€žÃ¥Â¤Â§Ã¥Â°Â
 */
template <class T>
int AVLTree<T>::max(int a, int b)
{
    return a>b ? a : b;
}

/*
 * Ã¥â€°ÂÃ¥ÂºÂÃ©ÂÂÃ¥Å½â€ "AVLÃ¦ â€˜"
 */
template <class T>
void AVLTree<T>::preOrder(AVLTreeNode<T>* tree) const
{
    if(tree != NULL)
    {
        cout<< tree->key << " " ;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::preOrder()
{
    preOrder(mRoot);
}

/*
 * Ã¤Â¸Â­Ã¥ÂºÂÃ©ÂÂÃ¥Å½â€ "AVLÃ¦ â€˜"
 */
template <class T>
void AVLTree<T>::inOrder(AVLTreeNode<T>* tree) const
{
    if(tree != NULL)
    {
        inOrder(tree->left);
        cout<< tree->key << " " ;
        inOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::inOrder()
{
    inOrder(mRoot);
}

/*
 * Ã¥ÂÅ½Ã¥ÂºÂÃ©ÂÂÃ¥Å½â€ "AVLÃ¦ â€˜"
 */
template <class T>
void AVLTree<T>::postOrder(AVLTreeNode<T>* tree) const
{
    if(tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<< tree->key << " " ;
    }
}

template <class T>
void AVLTree<T>::postOrder()
{
    postOrder(mRoot);
}

/*
 * (Ã©â‚¬â€™Ã¥Â½â€™Ã¥Â®Å¾Ã§Å½Â°)Ã¦Å¸Â¥Ã¦â€°Â¾"AVLÃ¦ â€˜x"Ã¤Â¸Â­Ã©â€Â®Ã¥â‚¬Â¼Ã¤Â¸ÂºkeyÃ§Å¡â€žÃ¨Å â€šÃ§â€šÂ¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::search(AVLTreeNode<T>* x, T key) const
{
    if (x==NULL || x->key==key)
        return x;

    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::search(T key)
{
    return search(mRoot, key);
}

/*
 * Ã¦Å¸Â¥Ã¦â€°Â¾Ã¦Å“â‚¬Ã¥Â°ÂÃ§Â»â€œÃ§â€šÂ¹Ã¯Â¼Å¡Ã¨Â¿â€Ã¥â€ºÅ¾treeÃ¤Â¸ÂºÃ¦ Â¹Ã§Â»â€œÃ§â€šÂ¹Ã§Å¡â€žAVLÃ¦ â€˜Ã§Å¡â€žÃ¦Å“â‚¬Ã¥Â°ÂÃ§Â»â€œÃ§â€šÂ¹Ã£â‚¬â€š
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

template <class T>
T AVLTree<T>::minimum()
{
    AVLTreeNode<T> *p = minimum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/*
 * Ã¦Å¸Â¥Ã¦â€°Â¾Ã¦Å“â‚¬Ã¥Â¤Â§Ã§Â»â€œÃ§â€šÂ¹Ã¯Â¼Å¡Ã¨Â¿â€Ã¥â€ºÅ¾treeÃ¤Â¸ÂºÃ¦ Â¹Ã§Â»â€œÃ§â€šÂ¹Ã§Å¡â€žAVLÃ¦ â€˜Ã§Å¡â€žÃ¦Å“â‚¬Ã¥Â¤Â§Ã§Â»â€œÃ§â€šÂ¹Ã£â‚¬â€š
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::maximum(AVLTreeNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T>
T AVLTree<T>::maximum()
{
    AVLTreeNode<T> *p = maximum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/*
 * LLÃ¯Â¼Å¡Ã¥Â·Â¦Ã¥Â·Â¦Ã¥Â¯Â¹Ã¥Âºâ€Ã§Å¡â€žÃ¦Æ’â€¦Ã¥â€ Âµ(Ã¥Â·Â¦Ã¥Ââ€¢Ã¦â€”â€¹Ã¨Â½Â¬)Ã£â‚¬â€š
 *
 * Ã¨Â¿â€Ã¥â€ºÅ¾Ã¥â‚¬Â¼Ã¯Â¼Å¡Ã¦â€”â€¹Ã¨Â½Â¬Ã¥ÂÅ½Ã§Å¡â€žÃ¦ Â¹Ã¨Å â€šÃ§â€šÂ¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
    AVLTreeNode<T>* k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max( height(k2->left), height(k2->right)) + 1;
    k1->height = max( height(k1->left), k2->height) + 1;

    return k1;
}

/*
 * RRÃ¯Â¼Å¡Ã¥ÂÂ³Ã¥ÂÂ³Ã¥Â¯Â¹Ã¥Âºâ€Ã§Å¡â€žÃ¦Æ’â€¦Ã¥â€ Âµ(Ã¥ÂÂ³Ã¥Ââ€¢Ã¦â€”â€¹Ã¨Â½Â¬)Ã£â‚¬â€š
 *
 * Ã¨Â¿â€Ã¥â€ºÅ¾Ã¥â‚¬Â¼Ã¯Â¼Å¡Ã¦â€”â€¹Ã¨Â½Â¬Ã¥ÂÅ½Ã§Å¡â€žÃ¦ Â¹Ã¨Å â€šÃ§â€šÂ¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>* k1)
{
    AVLTreeNode<T>* k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max( height(k1->left), height(k1->right)) + 1;
    k2->height = max( height(k2->right), k1->height) + 1;

    return k2;
}

/*
 * LRÃ¯Â¼Å¡Ã¥Â·Â¦Ã¥ÂÂ³Ã¥Â¯Â¹Ã¥Âºâ€Ã§Å¡â€žÃ¦Æ’â€¦Ã¥â€ Âµ(Ã¥Â·Â¦Ã¥ÂÅ’Ã¦â€”â€¹Ã¨Â½Â¬)Ã£â‚¬â€š
 *
 * Ã¨Â¿â€Ã¥â€ºÅ¾Ã¥â‚¬Â¼Ã¯Â¼Å¡Ã¦â€”â€¹Ã¨Â½Â¬Ã¥ÂÅ½Ã§Å¡â€žÃ¦ Â¹Ã¨Å â€šÃ§â€šÂ¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* k3)
{
    k3->left = rightRightRotation(k3->left);

    return leftLeftRotation(k3);
}

/*
 * RLÃ¯Â¼Å¡Ã¥ÂÂ³Ã¥Â·Â¦Ã¥Â¯Â¹Ã¥Âºâ€Ã§Å¡â€žÃ¦Æ’â€¦Ã¥â€ Âµ(Ã¥ÂÂ³Ã¥ÂÅ’Ã¦â€”â€¹Ã¨Â½Â¬)Ã£â‚¬â€š
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k1)
{
    k1->right = leftLeftRotation(k1->right);

    return rightRightRotation(k1);
}

/*
 * Ã¥Â°â€ Ã§Â»â€œÃ§â€šÂ¹Ã¦Ââ€™Ã¥â€¦Â¥Ã¥Ë†Â°AVLÃ¦ â€˜Ã¤Â¸Â­Ã¯Â¼Å’Ã¥Â¹Â¶Ã¨Â¿â€Ã¥â€ºÅ¾Ã¦ Â¹Ã¨Å â€šÃ§â€šÂ¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &tree, T key)
{
    if (tree == NULL)
    {
        // Ã¦â€“Â°Ã¥Â»ÂºÃ¨Å â€šÃ§â€šÂ¹
        tree = new AVLTreeNode<T>(key, NULL, NULL);
        if (tree==NULL)
        {
            return NULL;
        }
    }
    else if (key < tree->key) // Ã¥Âºâ€Ã¨Â¯Â¥Ã¥Â°â€ keyÃ¦Ââ€™Ã¥â€¦Â¥Ã¥Ë†Â°"treeÃ§Å¡â€žÃ¥Â·Â¦Ã¥Â­ÂÃ¦ â€˜"Ã§Å¡â€žÃ¦Æ’â€¦Ã¥â€ Âµ
    {
        tree->left = insert(tree->left, key);
        // Ã¦Ââ€™Ã¥â€¦Â¥Ã¨Å â€šÃ§â€šÂ¹Ã¥ÂÅ½Ã¯Â¼Å’Ã¨â€¹Â¥AVLÃ¦ â€˜Ã¥Â¤Â±Ã¥Å½Â»Ã¥Â¹Â³Ã¨Â¡Â¡Ã¯Â¼Å’Ã¥Ë†â„¢Ã¨Â¿â€ºÃ¨Â¡Å’Ã§â€ºÂ¸Ã¥Âºâ€Ã§Å¡â€žÃ¨Â°Æ’Ã¨Å â€šÃ£â‚¬â€š
        if (height(tree->left) - height(tree->right) == 2)
        {
            if (key < tree->left->key)
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        }
    }
    else if (key > tree->key) // Ã¥Âºâ€Ã¨Â¯Â¥Ã¥Â°â€ keyÃ¦Ââ€™Ã¥â€¦Â¥Ã¥Ë†Â°"treeÃ§Å¡â€žÃ¥ÂÂ³Ã¥Â­ÂÃ¦ â€˜"Ã§Å¡â€žÃ¦Æ’â€¦Ã¥â€ Âµ
    {
        tree->right = insert(tree->right, key);
        // Ã¦Ââ€™Ã¥â€¦Â¥Ã¨Å â€šÃ§â€šÂ¹Ã¥ÂÅ½Ã¯Â¼Å’Ã¨â€¹Â¥AVLÃ¦ â€˜Ã¥Â¤Â±Ã¥Å½Â»Ã¥Â¹Â³Ã¨Â¡Â¡Ã¯Â¼Å’Ã¥Ë†â„¢Ã¨Â¿â€ºÃ¨Â¡Å’Ã§â€ºÂ¸Ã¥Âºâ€Ã§Å¡â€žÃ¨Â°Æ’Ã¨Å â€šÃ£â‚¬â€š
        if (height(tree->right) - height(tree->left) == 2)
        {
            if (key > tree->right->key)
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }
    }
    tree->height = max( height(tree->left), height(tree->right)) + 1;

    return tree;
}

template <class T>
void AVLTree<T>::insert(T key)
{
    insert(mRoot, key);
}

/*
 * Ã¥Ë† Ã©â„¢Â¤Ã§Â»â€œÃ§â€šÂ¹(z)Ã¯Â¼Å’Ã¨Â¿â€Ã¥â€ºÅ¾Ã¦ Â¹Ã¨Å â€šÃ§â€šÂ¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z)
{
    // Ã¦ Â¹Ã¤Â¸ÂºÃ§Â©Âº Ã¦Ë†â€“Ã¨â‚¬â€¦ Ã¦Â²Â¡Ã¦Å“â€°Ã¨Â¦ÂÃ¥Ë† Ã©â„¢Â¤Ã§Å¡â€žÃ¨Å â€šÃ§â€šÂ¹Ã¯Â¼Å’Ã§â€ºÂ´Ã¦Å½Â¥Ã¨Â¿â€Ã¥â€ºÅ¾NULLÃ£â‚¬â€š
    if (tree==NULL || z==NULL)
        return NULL;

    if (z->key < tree->key)        // Ã¥Â¾â€¦Ã¥Ë† Ã©â„¢Â¤Ã§Å¡â€žÃ¨Å â€šÃ§â€šÂ¹Ã¥Å“Â¨"treeÃ§Å¡â€žÃ¥Â·Â¦Ã¥Â­ÂÃ¦ â€˜"Ã¤Â¸Â­
    {
        tree->left = remove(tree->left, z);
        // Ã¥Ë† Ã©â„¢Â¤Ã¨Å â€šÃ§â€šÂ¹Ã¥ÂÅ½Ã¯Â¼Å’Ã¨â€¹Â¥AVLÃ¦ â€˜Ã¥Â¤Â±Ã¥Å½Â»Ã¥Â¹Â³Ã¨Â¡Â¡Ã¯Â¼Å’Ã¥Ë†â„¢Ã¨Â¿â€ºÃ¨Â¡Å’Ã§â€ºÂ¸Ã¥Âºâ€Ã§Å¡â€žÃ¨Â°Æ’Ã¨Å â€šÃ£â‚¬â€š
        if (height(tree->right) - height(tree->left) == 2)
        {
            AVLTreeNode<T> *r =  tree->right;
            if (height(r->left) > height(r->right))
                tree = rightLeftRotation(tree);
            else
                tree = rightRightRotation(tree);
        }
    }
    else if (z->key > tree->key)// Ã¥Â¾â€¦Ã¥Ë† Ã©â„¢Â¤Ã§Å¡â€žÃ¨Å â€šÃ§â€šÂ¹Ã¥Å“Â¨"treeÃ§Å¡â€žÃ¥ÂÂ³Ã¥Â­ÂÃ¦ â€˜"Ã¤Â¸Â­
    {
        tree->right = remove(tree->right, z);
        // Ã¥Ë† Ã©â„¢Â¤Ã¨Å â€šÃ§â€šÂ¹Ã¥ÂÅ½Ã¯Â¼Å’Ã¨â€¹Â¥AVLÃ¦ â€˜Ã¥Â¤Â±Ã¥Å½Â»Ã¥Â¹Â³Ã¨Â¡Â¡Ã¯Â¼Å’Ã¥Ë†â„¢Ã¨Â¿â€ºÃ¨Â¡Å’Ã§â€ºÂ¸Ã¥Âºâ€Ã§Å¡â€žÃ¨Â°Æ’Ã¨Å â€šÃ£â‚¬â€š
        if (height(tree->left) - height(tree->right) == 2)
        {
            AVLTreeNode<T> *l =  tree->left;
            if (height(l->right) > height(l->left))
                tree = leftRightRotation(tree);
            else
                tree = leftLeftRotation(tree);
        }
    }
    else    // treeÃ¦ËœÂ¯Ã¥Â¯Â¹Ã¥Âºâ€Ã¨Â¦ÂÃ¥Ë† Ã©â„¢Â¤Ã§Å¡â€žÃ¨Å â€šÃ§â€šÂ¹Ã£â‚¬â€š
    {
        // treeÃ§Å¡â€žÃ¥Â·Â¦Ã¥ÂÂ³Ã¥Â­Â©Ã¥Â­ÂÃ©Æ’Â½Ã©ÂÅ¾Ã§Â©Âº
        if ((tree->left!=NULL) && (tree->right!=NULL))
        {
            if (height(tree->left) > height(tree->right))
            {
                // Ã¥Â¦â€šÃ¦Å¾Å“treeÃ§Å¡â€žÃ¥Â·Â¦Ã¥Â­ÂÃ¦ â€˜Ã¦Â¯â€Ã¥ÂÂ³Ã¥Â­ÂÃ¦ â€˜Ã©Â«ËœÃ¯Â¼â€º
                // Ã¥Ë†â„¢(01)Ã¦â€°Â¾Ã¥â€¡ÂºtreeÃ§Å¡â€žÃ¥Â·Â¦Ã¥Â­ÂÃ¦ â€˜Ã¤Â¸Â­Ã§Å¡â€žÃ¦Å“â‚¬Ã¥Â¤Â§Ã¨Å â€šÃ§â€šÂ¹
                //   (02)Ã¥Â°â€ Ã¨Â¯Â¥Ã¦Å“â‚¬Ã¥Â¤Â§Ã¨Å â€šÃ§â€šÂ¹Ã§Å¡â€žÃ¥â‚¬Â¼Ã¨Âµâ€¹Ã¥â‚¬Â¼Ã§Â»â„¢treeÃ£â‚¬â€š
                //   (03)Ã¥Ë† Ã©â„¢Â¤Ã¨Â¯Â¥Ã¦Å“â‚¬Ã¥Â¤Â§Ã¨Å â€šÃ§â€šÂ¹Ã£â‚¬â€š
                // Ã¨Â¿â„¢Ã§Â±Â»Ã¤Â¼Â¼Ã¤ÂºÅ½Ã§â€Â¨"treeÃ§Å¡â€žÃ¥Â·Â¦Ã¥Â­ÂÃ¦ â€˜Ã¤Â¸Â­Ã¦Å“â‚¬Ã¥Â¤Â§Ã¨Å â€šÃ§â€šÂ¹"Ã¥ÂÅ¡"tree"Ã§Å¡â€žÃ¦â€ºÂ¿Ã¨ÂºÂ«Ã¯Â¼â€º
                // Ã©â€¡â€¡Ã§â€Â¨Ã¨Â¿â„¢Ã§Â§ÂÃ¦â€“Â¹Ã¥Â¼ÂÃ§Å¡â€žÃ¥Â¥Â½Ã¥Â¤â€žÃ¦ËœÂ¯Ã¯Â¼Å¡Ã¥Ë† Ã©â„¢Â¤"treeÃ§Å¡â€žÃ¥Â·Â¦Ã¥Â­ÂÃ¦ â€˜Ã¤Â¸Â­Ã¦Å“â‚¬Ã¥Â¤Â§Ã¨Å â€šÃ§â€šÂ¹"Ã¤Â¹â€¹Ã¥ÂÅ½Ã¯Â¼Å’AVLÃ¦ â€˜Ã¤Â»ÂÃ§â€žÂ¶Ã¦ËœÂ¯Ã¥Â¹Â³Ã¨Â¡Â¡Ã§Å¡â€žÃ£â‚¬â€š
                AVLTreeNode<T>* max = maximum(tree->left);
                tree->key = max->key;
                tree->left = remove(tree->left, max);
            }
            else
            {
                // Ã¥Â¦â€šÃ¦Å¾Å“treeÃ§Å¡â€žÃ¥Â·Â¦Ã¥Â­ÂÃ¦ â€˜Ã¤Â¸ÂÃ¦Â¯â€Ã¥ÂÂ³Ã¥Â­ÂÃ¦ â€˜Ã©Â«Ëœ(Ã¥ÂÂ³Ã¥Â®Æ’Ã¤Â»Â¬Ã§â€ºÂ¸Ã§Â­â€°Ã¯Â¼Å’Ã¦Ë†â€“Ã¥ÂÂ³Ã¥Â­ÂÃ¦ â€˜Ã¦Â¯â€Ã¥Â·Â¦Ã¥Â­ÂÃ¦ â€˜Ã©Â«Ëœ1)
                // Ã¥Ë†â„¢(01)Ã¦â€°Â¾Ã¥â€¡ÂºtreeÃ§Å¡â€žÃ¥ÂÂ³Ã¥Â­ÂÃ¦ â€˜Ã¤Â¸Â­Ã§Å¡â€žÃ¦Å“â‚¬Ã¥Â°ÂÃ¨Å â€šÃ§â€šÂ¹
                //   (02)Ã¥Â°â€ Ã¨Â¯Â¥Ã¦Å“â‚¬Ã¥Â°ÂÃ¨Å â€šÃ§â€šÂ¹Ã§Å¡â€žÃ¥â‚¬Â¼Ã¨Âµâ€¹Ã¥â‚¬Â¼Ã§Â»â„¢treeÃ£â‚¬â€š
                //   (03)Ã¥Ë† Ã©â„¢Â¤Ã¨Â¯Â¥Ã¦Å“â‚¬Ã¥Â°ÂÃ¨Å â€šÃ§â€šÂ¹Ã£â‚¬â€š
                // Ã¨Â¿â„¢Ã§Â±Â»Ã¤Â¼Â¼Ã¤ÂºÅ½Ã§â€Â¨"treeÃ§Å¡â€žÃ¥ÂÂ³Ã¥Â­ÂÃ¦ â€˜Ã¤Â¸Â­Ã¦Å“â‚¬Ã¥Â°ÂÃ¨Å â€šÃ§â€šÂ¹"Ã¥ÂÅ¡"tree"Ã§Å¡â€žÃ¦â€ºÂ¿Ã¨ÂºÂ«Ã¯Â¼â€º
                // Ã©â€¡â€¡Ã§â€Â¨Ã¨Â¿â„¢Ã§Â§ÂÃ¦â€“Â¹Ã¥Â¼ÂÃ§Å¡â€žÃ¥Â¥Â½Ã¥Â¤â€žÃ¦ËœÂ¯Ã¯Â¼Å¡Ã¥Ë† Ã©â„¢Â¤"treeÃ§Å¡â€žÃ¥ÂÂ³Ã¥Â­ÂÃ¦ â€˜Ã¤Â¸Â­Ã¦Å“â‚¬Ã¥Â°ÂÃ¨Å â€šÃ§â€šÂ¹"Ã¤Â¹â€¹Ã¥ÂÅ½Ã¯Â¼Å’AVLÃ¦ â€˜Ã¤Â»ÂÃ§â€žÂ¶Ã¦ËœÂ¯Ã¥Â¹Â³Ã¨Â¡Â¡Ã§Å¡â€žÃ£â‚¬â€š
                AVLTreeNode<T>* min = minimum(tree->right);
                tree->key = min->key;
                tree->right = remove(tree->right, min);
            }
        }
        else
        {
            AVLTreeNode<T>* tmp = tree;
            tree = (tree->left!=NULL) ? tree->left : tree->right;
            delete tmp;
        }
    }

    return tree;
}

template <class T>
void AVLTree<T>::remove(T key)
{
    AVLTreeNode<T>* z;

    if ((z = search(mRoot, key)) != NULL)
        mRoot = remove(mRoot, z);
}

/*
 * Ã©â€â‚¬Ã¦Â¯ÂAVLÃ¦ â€˜
 */
template <class T>
void AVLTree<T>::destroy(AVLTreeNode<T>* &tree)
{
    if (tree==NULL)
        return ;

    if (tree->left != NULL)
        destroy(tree->left);
    if (tree->right != NULL)
        destroy(tree->right);

    delete tree;
}

template <class T>
void AVLTree<T>::destroy()
{
    destroy(mRoot);
}

void input() {
    ifstream infile("test.txt");
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        // Ã¥Ë†ÂÃ¥Â§â€¹Ã¥Å’â€“AVLÃ¦ â€˜
        AVLTree<int>* tree=new AVLTree<int>();

        string data;
        while(data != "IN" && data != "POST" && data != "PRE") {

            getline(ss, data, ' ');

            // Ã¨Â¾â€œÃ¥â€¡ÂºAVLÃ¦ â€˜
            if (data == "IN" || data == "POST" || data == "PRE") {

                // Ã¨Â¾â€œÃ¥â€¡Âº
                if (!tree->height()) {
                    cout << "EMPTY";
                } else if (data == "IN") {
                    tree->inOrder();
                } else if (data == "POST") {
                    tree->postOrder();
                } else {
                    tree->preOrder();
                }
                tree->destroy();

                // cout << endl;

                break;

            } else {
                string operation = data.substr(0, 1);
                int value = stoi(data.substr(1, data.length() - 1));

                if (operation == "A") {
                    tree->insert(value);
                } else if (operation == "D") {
                    tree->remove(value);
                }
            }

            data = "";
        }

    }
}

int main()
{

    input();
    return 0;
}