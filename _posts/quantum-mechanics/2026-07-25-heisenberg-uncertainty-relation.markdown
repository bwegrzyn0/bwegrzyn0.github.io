---
layout: post
title: "Heisenberg uncertainty relation"
date: 2026-07-25
katex: true
category: quantum-mechanics
---

### Measurement in quantum mechanics 
Let us consider an operator associated with the measurement of an ***observable***, for example position or momentum, which we will denote in general as $A$. We will denote the ***eigenkets (eigenvectors)*** of the operator as $\ket{a'}$ and the associated eigenvalues as $a'$. This means that we have the following equality:
\$$ A\ket{a'}=a'\ket{a'}. \tag{1} \$$
We see that when the operator acts on one of its eigenkets, we get a measured value $a'$ associated with that eigenket in return. 

>***Theorem.*** Because $a'$ is a value that is actually measured, it must be real. From this follows that the operator $A$ must be **hermitian**, i.e. $A=A^\dag$, where $^\dag$ denotes the hermitian adjoint (conjugate transpose). <br> ***Proof***: We will take the hermitian adjoint of (1), which gives us:
>\$$ \bra{a'} A^\dag = \bra{a'} a'^\ast, \$$
>where $\bra{a'}$ is called the **bra** and is an element of the dual space of the ket vector space. We will now multiply both sides of the equation by $\ket{a'}$:
>\$$ \bra{a'} A^\dag \ket{a'}=\bra{a'} a'^\ast \ket{a'}. \$$
>We now use the fact that $a'\in\mathbb{R}$, so $a'=a'^\ast$. Notice that we now get $a'\ket{a'}=A\ket{a'}$ on the RHS. Using this:
>\$$ \bra{a'} A^\dag \ket{a'}=\bra{a'} A \ket{a'} \iff \bra{a'}(A-A^\dag)\ket{a'} =0, \$$
>so $A=A^\dag$. $\blacksquare$

Let us consider a state $\ket{\alpha}$, not necessarily being an eigenket of $A$. What quantum mechanics postulates, is that once a measurement of an observable associated with $A$ is taken, the state $\ket{\alpha}$ is randomly thrown into one of the eigenkets of $A$. The probability of being thrown into the state $\ket{a'}$ is $\lvert\braket{a' \vert \alpha}\rvert^2$.
\$$ \ket{\alpha} \xrightarrow{\text{measurement}} \ket{a'} \text{ with probability } \lvert\braket{a' \vert \alpha}\rvert^2. \tag{2} \$$

### The expectation value of an operator
We will now consider an ensemble of states $\ket{\alpha}$, i.e. we have as many identical $\ket{\alpha}$ states as we need. We will measure each of the states using our $A$ operator and calculate the average measured value we got.

Because $\ket{\alpha}$ is thrown into different $\ket{a'}$ states randomly, each one has a certain probability to occur and give a measured value $a'$ in agreement with (1). For now we will denote the probability of the state by $p(a')$. We now use the standard definition of the average:
\$$ \braket{A} = \sum_{a'} p(a') a'. \$$
We recall from (2) that
\$$ p(a')=\lvert\braket{a' \vert \alpha}\rvert^2=\braket{a' \vert \alpha}^\ast\braket{a' \vert \alpha}=\braket{\alpha \vert a'}\braket{a' \vert \alpha}, \$$
so
\$$ \braket{A} = \bra{\alpha} \left(\sum_{a'} \ket{a'}\bra{a'} a'\right) \ket{\alpha}. \$$
We will calculate the sum inside the parentheses:
\$$ \sum_{a'} a'\ket{a'}\bra{a'}  = \sum_{a'} A\ket{a'}\bra{a'} = A\sum_{a'} \ket{a'}\bra{a'}. \$$
The eigenkets of $A$ are postulated to form a complete vector space, i.e.
\$$ \sum_{a'} \ket{a'}\bra{a'} = 1, \$$
where $1$ signifies the identity matrix. As a result we arrive at the formula for the **expectation value** of the operator $A$ with respect to the state $\ket{\alpha}$:
\$$ \braket{A} = \bra{\alpha} A \ket{\alpha}. \tag{3} \$$

### The dispersion of an operator
We define the **dispersion** of $A$ as:
\$$ \braket{(\Delta A)^2}= \braket{ \left(A-\braket{A}\right)^2}, \$$
which should be reminiscent of the mean of variance in statistics. We will expand the parentheses to arrive at a different expression for dispersion:
\$$ \braket{ \left(A-\braket{A}\right)^2}=\braket{ A^2 -2A\braket{A} +\braket{A}^2}=\braket{A^2} -2\braket{A}\braket{A} + \braket{A}^2 \$$
\$$ \braket{(\Delta A)^2}=\braket{A^2} - \braket{A}^2. \$$

### Cauchy-Schwarz inequality
>***Theorem.*** In order to prove Heisenberg's uncertainty relation, we will first need the Cauchy-Schwarz inequality, which states that:
>\$$ \braket{\alpha \vert \alpha} \braket{\beta \vert \beta} \ge \left\lvert \braket{\alpha \vert \beta} \right\rvert ^2. \tag{4} \$$
>In $\mathbb{R}^3$ it reduces to:
>\$$ AB \ge  \left\lvert \vec{A}\cdot\vec{B} \right\rvert. \$$
>We will first prove the inequality in $\mathbb{R}^3$ and then move to the general case.
><br> ***Proof in $\mathbb{R}^3$***:
>Consider the vector $\vec{U}$, being the projection of $\vec{A}$ onto $\vec{B}$:
>\$$ \vec{U} = \left(\vec{A}\cdot \hat{B}\right) \hat{B}, \$$
>where $\hat{B}=\vec{B}/B$ is the unit vector in the direction of $\vec{B}$. We now consider what remains, that is $\vec{V}=\vec{A}-\vec{U}$:
>\$$ \vec{V} = \vec{A} - \frac{\vec{A}\cdot\vec{B}}{B^2}\vec{B}. \$$
>We also know that $V^2= \vec{V}\cdot\vec{V}\ge 0$, so:
>\$$ V^2 = \left(\vec{A} - \frac{\vec{A}\cdot\vec{B}}{B^2}\vec{B}\right)^2 = \vec{A}\cdot\vec{A} - 2\frac{(\vec{A}\cdot\vec{B})^2}{B^2} + \frac{(\vec{A}\cdot\vec{B})^2}{B^4}B^2= A^2 - \frac{(\vec{A}\cdot\vec{B})^2}{B^2} \ge 0.  \$$
>Rearranging, we get
>\$$ AB\ge \left\lvert\vec{A}\cdot\vec{B}\right\rvert. \, \blacksquare\$$
>***General proof***:
>We consider the ket
>\$$ \ket{\gamma} = \ket{\alpha} - \frac{\braket{\beta \vert \alpha}}{\braket{\beta\vert \beta}}\ket{\beta}. \$$
>One of the axioms of a vector space is that $\braket{c \vert c} \ge 0$, so
>\$$ \braket{c \vert c} = \left( \bra{\alpha} - \bra{\beta}\frac{\braket{\alpha \vert \beta}}{\braket{\beta\vert \beta}}\right)\left(\ket{\alpha} - \frac{\braket{\beta \vert \alpha}}{\braket{\beta\vert \beta}}\ket{\beta}\right)= \$$
>\$$ = \braket{\alpha \vert \alpha} - \frac{\braket{\alpha\vert\beta}\braket{\beta\vert\alpha}}{\braket{\beta\vert\beta}} - \frac{\braket{\beta\vert\alpha}\braket{\alpha\vert\beta}}{\braket{\beta\vert\beta}} + \frac{\braket{\beta\vert\alpha}\braket{\alpha\vert\beta}}{\lvert\braket{\beta\vert\beta}\rvert^2}\braket{\beta\vert\beta} = \$$
>\$$ = \braket{\alpha \vert \alpha} - \frac{\lvert\braket{\alpha\vert\beta}\rvert^2}{\braket{\beta\vert\beta}} \ge 0, \$$
>from which we easily get the desired result. $\blacksquare$

### The uncertainty relation
We consider the kets
\$$ \ket{\alpha} = \Delta A \ket{\gamma}, \, \ket{\beta} = \Delta B \ket{\gamma}, \$$
where $\ket{\gamma}$ is an arbitrary ket of our choice. $\Delta A\ket{\alpha}$ means $A\ket{\alpha} - \bra{\alpha} A \ket{\alpha} \ket{\alpha}$.

>***Lemma 1:*** If $A=A^\dag$, the same follows for $\Delta A$. <br> ***Proof:***
>\$$ \left( \Delta A\right)^\dag = A^\dag - \bra{\alpha} A^\dag \ket{\alpha} = A- \bra{\alpha} A \ket{\alpha} = \Delta A. \,\square \$$

>***Lemma 2:*** $[\Delta A, \Delta B] = [A, B]$. <br> ***Proof:***
>\$$ [\Delta A, \Delta B]= \Delta A \Delta B - \Delta B\Delta A=(A-\braket{A})(B-\braket{B}) - (B-\braket{B})(A-\braket{A})= \$$
>\$$ = AB - A\braket{B} - B\braket{A} + \braket{A}\braket{B} - BA + B\braket{A} + A\braket{B} - \braket{A}\braket{B} = AB - BA = [A, B]. \, \square \$$


>***Lemma 3:*** The expectation value of a commutator of hermitian operators is imaginary and of an anticommutator is real.  <br> ***Proof:***
> The commutator is anti-hermitian: 
> \$$ [A,B]^\dag=B^\dag A^\dag - A^\dag B^\dag = BA - AB = -[A, B]. \$$
> The anticommutator is hermitian:
> \$$ \lbrace A, B \rbrace^\dag = B^\dag A^\dag + A^\dag B^\dag = BA+AB = \lbrace A, B \rbrace. \$$
> For hermitian operators, say $C=C^\dag$:
> \$$ \braket{C}=\bra{\alpha} C \ket{\alpha} = \bra{\alpha} C^\dag \ket{\alpha} = (\bra{\alpha} C \ket{\alpha})^\ast, \$$
> so the expectation value of $C=\lbrace A, B \rbrace$ is real. For $D=-D^\dag$:
> \$$ \braket{D}=\bra{\alpha} D \ket{\alpha} = -\bra{\alpha} D^\dag \ket{\alpha} = -(\bra{\alpha} D \ket{\alpha})^\ast, \$$
> so $\braket{D}=\braket{[A, B]}$ is imaginary. $\square$


We now plug in both kets into the Cauchy-Schwarz inequality (4):
\$$ \braket{\alpha \vert \alpha} \braket{\beta \vert \beta} \ge \left\lvert \braket{\alpha \vert \beta} \right\rvert ^2 \$$
\$$ \bra{\gamma} (\Delta A)^\dag \Delta A \ket{\gamma} \bra{\gamma} (\Delta B)^\dag \Delta B \ket{\gamma} \ge \left\lvert \bra{\gamma} (\Delta A)^\dag \Delta B \ket{\gamma} \right\rvert ^2 \$$
and using the the result of lemma 1:
\$$ \bra{\gamma} \Delta A \Delta A \ket{\gamma} \bra{\gamma} \Delta B \Delta B \ket{\gamma} \ge \left\lvert \bra{\gamma} \Delta A \Delta B \ket{\gamma} \right\rvert ^2. \$$
Using (3):
\$$ \braket{(\Delta A)^2} \braket{(\Delta B)^2} \ge \left\lvert \braket{\Delta A \Delta B} \right\rvert ^2. \$$
Notice that
\$$ \Delta A \Delta B = \frac{1}{2}\Delta A \Delta B - \frac{1}{2} \Delta B \Delta A + \frac{1}{2} \Delta A \Delta B + \frac{1}{2}\Delta B \Delta A = \frac{1}{2} [\Delta A, \Delta B] + \frac{1}{2} \lbrace \Delta A, \Delta B \rbrace. \$$
We use lemma 2 to write:
\$$ \braket{(\Delta A)^2} \braket{(\Delta B)^2} \ge \frac{1}{4}\left\lvert \braket{[A,  B]} + \braket{\lbrace \Delta A, \Delta B \rbrace} \right\rvert ^2 \$$
We will now use lemma 3 to evaluate RHS. Because the first term is purely imaginary and the second one purely real,
\$$ \left\lvert \braket{[A,  B]} + \braket{\lbrace \Delta A, \Delta B \rbrace} \right\rvert ^2 = \left\lvert \braket{[A,  B]} \right\rvert^2 + \left\lvert\braket{\lbrace \Delta A, \Delta B \rbrace} \right\rvert ^2. \$$
We omit the second term in the above equation to make the inequality stronger and arrive at
\$$ \boxed{\braket{(\Delta A)^2} \braket{(\Delta B)^2} \ge \frac{1}{4}\left\lvert \braket{[A,  B]} \right\rvert ^2.} \tag{5} \$$
The above inequality states that if we deal with incompatible observables ($[A, B]\neq 0$), we cannot measure both of them simultaneously with arbitrary precision. Decreasing the dispersion of one observable will, by virtue of the inequality, increase the dispersion of the second one.

We will use one of the ***canonical commutation relations***:
\$$ [x_i, p_j] = i\hbar \delta_{ij}, \$$
where $x_i$ is the i-th component of the position operator (x, y, z) and the same for $p$. Plugging it into (5) we arrive at the ***Heisenberg uncretainty relation***:
\$$ \boxed{\braket{(\Delta x_i)^2} \braket{(\Delta p_j)^2} \ge \frac{\hbar^2}{4}\delta_{ij}.} \$$
