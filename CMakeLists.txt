cmake_minimum_required(VERSION 3.5)
project(Leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BestTimeToBuyAndSellII.h PatchingArray.h JumpGame.h GasStation.h JumpGameII.h quick_sort.h MaximumDepthOfBinaryTree.h InvertBinaryTree.h SameTree.h BinaryTreePreorderTraversal.h BinaryTreeInorderTraversal.h BinaryTreePostorderTraversal.h LCA.h KthSmallestElement.h UniqueBinarySearchTree.h ConvertSortedArrayToBinarySearchTree.h HouseRobberIII.h NextRightPointers.h NQueensII.h GenerateParentheses.h GrayCode.h CominationSumIII.h CombinationSum.h BurstBollons.h MaxSquare.h EditDistance.h ValidAnagram.h LongestSubString.h InsertionSort.h RemoveDuplicate.h ConstructBinaryTree.h HeapSort.h BulkSort.h CountingSort.h BubbleSort.h InsertSort.h MyString.h FindValueInMatrix.h replace_space.h MyLinkedList.h ReconstructTree.h  QueueOfStack.h DeleteNode.h Reorder.h MinStack.h PrintTree.h VerifySequenceOfBST.h FindPath.h CloneComplexLinkList.h ConvertBSTToDiLInkList.h Permutations.h ReversePair.h DuplicateCount.h)
add_executable(Leetcode ${SOURCE_FILES})