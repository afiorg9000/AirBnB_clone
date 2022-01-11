<h1 class="gap"> The Monty project</h1>

<h3>The Monty language</h3>

<p>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</p>

<p><strong>Monty byte code files</strong></p>

<p>Files containing Monty byte codes usually have the <code>.m</code> extension. Most of the industry uses this standard but it is not required by the specification of the language.
There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:</p>

<pre><code>julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
</code></pre>

<p>Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:</p>

<pre><code>julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
</code></pre>


<h2>Learning Objectives</h2>

<p> As third trimester student at Holberton School, this is a purely educational project that seeks that when finished I can understand and explain the following topics:</p>

<ul>
<li>What do LIFO and FIFO mean</li>
<li>What is a stack, and when to use it</li>
<li>What is a queue, and when to use it</li>
<li>What are the common implementations of stacks and queues</li>
<li>What are the most common use cases of stacks and queues</li>
<li>What is the proper way to use global variables</li>
</ul>


<h3>Compilation &amp; Output</h3>

<ul>
<li>The code must be compiled this way:</li>
</ul>

<pre><code>$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
</code></pre>

<ul>
<li>Any output must be printed on <code>stdout</code></li>
<li>Any error message must be printed on <code>stderr</code>
</ul>


<h3>Data structures</h3>

<p> There is an specific data structure for this project and is included in the header file: </p>

<pre><code>/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
</code></pre>

<pre><code>/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
</code></pre>
