# Neural Networks in C++ — Learn by Doing

A progressive set of exercises to understand neural networks from scratch using C++.
No frameworks — just raw math and code so you truly understand what's happening.

After completing all exercises, you'll be able to answer every question in the
**Self-Check Questions** section at the bottom.

---

## Core Concepts

### What is a Neural Network?

A neural network is a function that maps inputs to outputs through layers of
interconnected "neurons." Each connection has a **weight**, and each neuron has
a **bias**. The network *learns* by adjusting these weights and biases to
minimize error on a given task.

```
Input Layer      Hidden Layer      Output Layer
  [x1] ---w1---> [h1] ---w5--->
              \        \            [o1]
  [x2] ---w2---> [h2] ---w6--->
```

### Key Building Blocks

| Concept | What it does |
|---|---|
| **Neuron** | Computes `output = activation(w1*x1 + w2*x2 + ... + bias)` |
| **Weight** | Controls how much influence one neuron has on another |
| **Bias** | Shifts the activation function left or right |
| **Activation Function** | Introduces non-linearity (sigmoid, ReLU, tanh) |
| **Forward Pass** | Push input through the network to get an output |
| **Loss Function** | Measures how wrong the network's output is |
| **Backpropagation** | Calculates how to adjust each weight to reduce the loss |
| **Gradient Descent** | Iteratively updates weights in the direction that reduces loss |
| **Learning Rate** | Controls how big each weight update step is |
| **Epoch** | One full pass through the entire training dataset |

---

## Exercise Roadmap

Work through these in order. Each builds on the previous one.

### Exercise 1: Images and Tensors (`01_images_and_tensors.cpp`)
**Covers:** Image representation, tensors, rank, shape, broadcasting, vectorized operations

- Learn how grayscale and color images are stored as numbers
- Understand tensors: rank-1 (vector), rank-2 (matrix), rank-3 (e.g. color image)
- Practice creating, slicing, and broadcasting arrays
- See how vectorized operations beat loops for speed

### Exercise 2: Pixel Similarity Classifier (`02_pixel_similarity.cpp`)
**Covers:** MNIST dataset structure, pixel similarity, L1 norm, RMSE

- Understand how MNIST data is organized (folders by digit class)
- Build a simple digit classifier using pixel-by-pixel comparison
- Implement L1 (mean absolute error) and RMSE distance metrics
- Learn why this approach works but has limitations

### Exercise 3: Loss Functions and Metrics (`03_loss_and_metrics.cpp`)
**Covers:** MSE, RMSE, L1, cross-entropy, loss vs metrics, why not accuracy, training vs validation

- Implement multiple loss functions and understand when to use each
- Understand the crucial difference between a loss function and a metric
- Learn why accuracy can't be used as a loss function (not differentiable)
- Understand why metrics use the validation set, not the training set

### Exercise 4: Activation Functions (`04_activation_functions.cpp`)
**Covers:** Sigmoid, ReLU, tanh, non-linearity, universal approximation theorem

- Implement sigmoid, ReLU, and tanh with their derivatives
- Understand why non-linearity is essential
- Draw/plot activation functions from code output
- Learn why deeper networks work better despite the universal approximation theorem

### Exercise 5: SGD and Gradients (`05_sgd_and_gradients.cpp`)
**Covers:** SGD, 7 steps, weight initialization, learning rate, gradients, weight update rule

- Understand what a gradient is and why we need it
- Learn the 7 steps of SGD for machine learning
- Implement weight initialization and gradient descent
- See what happens with too-high vs too-low learning rates

### Exercise 6: Neurons, Bias, and Forward Pass (`06_neurons_and_forward_pass.cpp`)
**Covers:** Single neuron, bias parameters, matrix multiplication (@), forward pass

- Build a single neuron and understand every component
- Learn why bias parameters are essential
- Implement matrix multiplication (the @ operator in Python)
- Build a multi-layer forward pass

### Exercise 7: Backpropagation and Training Loop (`07_backprop_and_training.cpp`)
**Covers:** Backward method, zeroing gradients, training loop, DataLoader concept

- Implement backpropagation (the "backward" pass)
- Understand why we must zero gradients before each backward pass
- Build a complete training loop with pseudocode parallels
- Implement a simple DataLoader that batches data

### Exercise 8: XOR Network (`08_xor_network.cpp`)
**Covers:** Full network, mini-batches, validation, putting it all together

- Build a complete 2-2-1 neural network
- Solve the XOR problem (not linearly separable)
- Use mini-batch training and track validation metrics
- Capstone: if you can do this, you understand neural networks

---

## How to Build & Run

Each file is standalone. Compile with any C++17 compiler:

```bash
# Windows (MSVC)
cl /EHsc /std:c++17 01_images_and_tensors.cpp /Fe:01.exe

# GCC / MinGW
g++ -std=c++17 -o 01 01_images_and_tensors.cpp

# Then run
./01
```

---

## Tips for Success

1. **Do the exercises in order.** Each one builds on the last.
2. **Don't peek at solutions immediately.** Struggle a bit — that's learning.
3. **Print intermediate values.** Add `cout` to see what the network computes.
4. **Play with the learning rate.** Too high = overshooting. Too low = slow.
5. **Draw the network on paper** before coding. Label every weight and bias.
6. **Read the THEORY sections** in each file — they answer the self-check questions.

---

## Self-Check Questions

After completing all exercises, you should be able to answer these:

1. How is a grayscale image represented on a computer? How about a color image?
2. How are the files and folders in the MNIST_SAMPLE dataset structured? Why?
3. Explain how the "pixel similarity" approach to classifying digits works.
4. What is a list comprehension? Create one that selects odd numbers and doubles them.
5. What is a "rank-3 tensor"?
6. What is the difference between tensor rank and shape? How do you get the rank from the shape?
7. What are RMSE and L1 norm?
8. How can you apply a calculation on thousands of numbers at once, many thousands of times faster than a Python loop?
9. Create a 3x3 tensor containing numbers 1 to 9. Double it. Select the bottom-right four numbers.
10. What is broadcasting?
11. Are metrics generally calculated using the training set, or the validation set? Why?
12. What is SGD?
13. Why does SGD use mini-batches?
14. What are the seven steps in SGD for machine learning?
15. How do we initialize the weights in a model?
16. What is "loss"?
17. Why can't we always use a high learning rate?
18. What is a "gradient"?
19. Do you need to know how to calculate gradients yourself?
20. Why can't we use accuracy as a loss function?
21. Draw the sigmoid function. What is special about its shape?
22. What is the difference between a loss function and a metric?
23. What is the function to calculate new weights using a learning rate?
24. What does the DataLoader class do?
25. Write pseudocode showing the basic steps taken in each epoch for SGD.
26. Create a function that, if passed `[1,2,3,4]` and `'abcd'`, returns `[(1,'a'),(2,'b'),(3,'c'),(4,'d')]`. What is special about that output?
27. What does `view` do in PyTorch?
28. What are the "bias" parameters in a neural network? Why do we need them?
29. What does the `@` operator do in Python?
30. What does the `backward` method do?
31. Why do we have to zero the gradients?
32. What information do we have to pass to `Learner`?
33. Show pseudocode for the basic steps of a training loop.
34. What is "ReLU"? Draw a plot of it for values from -2 to +2.
35. What is an "activation function"?
36. What's the difference between `F.relu` and `nn.ReLU`?
37. The universal approximation theorem shows that any function can be approximated as closely as needed using just one nonlinearity. So why do we normally use more?

---

## Further Reading

After completing these exercises, explore:
- **Softmax + Cross-Entropy** for multi-class classification
- **Convolutional Neural Networks (CNNs)** for image recognition
- **Recurrent Neural Networks (RNNs)** for sequences
- **Regularization** (dropout, L2) to prevent overfitting
- **Optimizers** (Adam, RMSprop) beyond vanilla gradient descent
