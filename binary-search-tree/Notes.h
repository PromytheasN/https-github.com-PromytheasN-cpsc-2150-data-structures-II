    if( originalNode->left != nullptr){ // If left node exists
      newNode->left = new TreeNode(originalNode->left->element); // Create newNode on parrents left
      subTreeCopy(newNode->left, originalNode->left); // Call function copy left subtree recursively
    }

    // Copy right subtree
    if(originalNode->right != nullptr){ // If right node exists
      newNode->right = new TreeNode(originalNode->right->element); // Create newNode on parrents right
      subTreeCopy(newNode->right, originalNode->right); // Call function copy right subtree recursively
    }