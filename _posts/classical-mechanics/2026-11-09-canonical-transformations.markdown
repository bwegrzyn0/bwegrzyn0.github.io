---
layout: post
title: "Canonical transformations"
date: 2026-11-09
katex: true
category-displayed: "Classical mechanics"
category: "classical-mechanics"
excerpt: "In this article we derive the Hamilton's equations both from the Lagrangian formulation, as well as directly from a variational principle. This enables us to develop the language of canonical transformations, which will prove themselves to be a powerful tool in future posts."
---

## Hamilton's equations
Let's consider the total differential of the Lagrangian $\mathcal{L}=\mathcal{L}(q, \dot{q}, t)$, where $q_i$ are generalized coordinates:
\$$ d\mathcal{L} = \frac{\partial \mathcal{L}}{\partial q_i} dq_i + \frac{\partial \mathcal{L}}{\partial \dot{q}\_i} d\dot{q}\_i + \frac{\partial\mathcal{L}}{\partial t} dt. \$$
We make use of Einstein's summation convention, where we sum over any repeated index, so here $i$. We can make use of the definition of the momentum $p_i$ conjugate to the variable $q_i$:
\$$ p_i = \frac{\partial \mathcal{L}}{\partial \dot{q}\_i} \$$
and of the Euler-Lagrange equation:
\$$ \dot{p}\_i = \frac{\partial\mathcal{L}}{\partial q_i} \$$
to write the differential as
\$$ d\mathcal{L} = \dot{p}\_i dq_i + p_i d\dot{q}\_i + \frac{\partial\mathcal{L}}{\partial t} dt. \$$
We would like some of the terms to simplify and we are especially looking for another total differential. We can create one by noticing that
\$$ p_i d\dot{q}\_i = d\left( p_i \dot{q}\_i\right) - \dot{q}\_i dp_i. \$$
We plug this into the total differential and rearrange terms to arrive at
\$$ d\left(\mathcal{L} - p_i \dot{q}\_ i\right) = \dot{p}\_i dq_i - \dot{q}\_i dp_i + \frac{\partial\mathcal{L}}{\partial t} dt. \$$  
Let us define the **Hamiltonian** as
\$$ \mathcal{H}\equiv\mathcal{H}(q, p, t) = p_i\dot{q}\_i - \mathcal{L}. \$$
Its total differential is then
\$$ d\mathcal{H} = -\dot{p}\_i dq_i + \dot{q}\_i dp_i - \frac{\partial\mathcal{L}}{\partial t} dt, \$$
from which the following relations, known as **Hamilton's equations** follow:
\$$ \dot{p}\_i=-\frac{\partial\mathcal{H}}{\partial q_i}, \$$
\$$ \dot{q}\_i=\frac{\partial\mathcal{H}}{\partial p_i}. \$$
We also have an additional relation:
\$$ \left( \frac{\partial\mathcal{H}}{\partial t} \right)\_{p,q} = -\left( \frac{\partial\mathcal{L}}{\partial t} \right)\_{p,q}, \$$
with $p$ and $q$ held constant. Time is a certain parameter that both $\mathcal{H}$ and $\mathcal{L}$ depend upon. However, it could be any other parameter $\lambda$, which can be easily introduced into the total differential and the same relationship can be proven to hold for it.

Hamilton's equations ultimately give us the same results as those that we would get from the Lagrangian formulation of mechanics. This time, however, $q$ and $p$ are treated as completely *separate and independent* variables, unlike $q$ and $\dot{q}$. Because of that, we are left with two first order equations instead of a single second order one. The power of Hamilton's formulation, however, lies in canonical transformations.

### Hamilton's equations derived from a variational principle
Before proceeding to canonical transformations, we need to see how Hamilton's equations can be derived from a variational principle and what significant observations follow from the derivation.

We know that, according to Hamilton's principle, the variation of action is zero:
\$$ \delta \int_{t_1}^{t_2} \mathcal{L}\,dt = 0. \$$
We also know, by definition, that
\$$ \mathcal{L} = \dot{q}\_i p_i - \mathcal{H}(q, p, t), \$$
so we are left with
\$$ \delta \int_{t_1}^{t_2} f(q, p, \dot{q}, \dot{p}, t) \,dt = 0, \$$
where the expression for $f$ is the same as the Lagrangian above. We don't use the same notation however, as the Lagrangian is a function of only $q$, $\dot{q}$ and $t$. The above equation is known as modified Hamilton's principle. From Euler-Lagrange equations:
\$$ \frac{d}{dt}\left( \frac{\partial f}{\partial \dot{q}\_i}\right) = \frac{\partial f}{\partial q_i} \$$
and 
\$$ \frac{d}{dt}\left( \frac{\partial f}{\partial \dot{p}\_i}\right) = \frac{\partial f}{\partial p_i}. \$$
Evaluating those derivatives gives back Hamilton's equations, which is left as an exercise for the reader.

The most important point is to consider what happens, when we add $dF/dt$, where $F=F(q,p,t)$ to the integrand. We have then an additional term:
\$$ \delta\int_{t_1}^{t_2} \frac{dF}{dt}\,dt = \delta\left(F(q(t_2), p(t_2), t_2) - F(q(t_1), p(t_1), t_1)\right), \$$
which follows from the fundamental theorem of calculus. The vartiation of $t_1$ and $t_2$ is obviously zero by definition, as well as $\delta q(t_1)=\delta q(t_2)=0$. If we additionally assume that $\delta p(t_1)=\delta p(t_2) =0$, we can say that the variation of the parentheses is zero (as $F$ changes only with $q$, $p$ or $t$). This means that we can add an arbitrary function $dF/dt$ to modified Hamilton's principle and it won't make a difference. This is a key observation, which will allow us to check, whether a transformation is canonical.

## Canonical transformations
A **canonical transformation** is a transformation from $(q, p, t)$ to another set of variables $(Q, P, t)$, which preserves the form of Hamilton's equations. This means that if
\$$ \dot{q}\_i = \frac{\partial \mathcal{H}}{\partial p_i} \$$
\$$ \dot{p}\_i = -\frac{\partial \mathcal{H}}{\partial q_i}, \$$
then
\$$ \dot{Q}\_i = \frac{\partial \mathcal{K}}{\partial P_i} \$$
\$$ \dot{P}\_i = -\frac{\partial \mathcal{K}}{\partial Q_i}, \$$
where $\mathcal{K}=\mathcal{K}(Q, P, t)$ is the transformed hamiltonian.

We want to look for something that will let us decide, whether a given transformation is canonical. From the variational principle derived earlier, we know that
\$$ \delta\int_{t_1}^{t_2} \dot{q}\_i p_i - \mathcal{H}(q, p, t)\,dt = 0. \$$
But, if $(Q, P)$ are a valid set of canonical coordinates, we should also have
\$$ \delta\int_{t_1}^{t_2} \dot{Q}\_i P_i - \mathcal{K}(Q, P, t)\,dt = 0. \$$
This means that 1) the integrands differ by a constant factor, which is an uninteresting case, or 2) the integrands differ by $dF/dt$, where $F$ is a function which we described earlier. This gives us
\$$ \dot{q}\_i p_i - \mathcal{H}(q, p, t) = \dot{Q}\_i P_i - \mathcal{K}(Q, P, t) + \frac{dF}{dt}. \$$
The function, in general, depends on all old and new canonical variables plus time. It is called the **generating function** for a canonical transformation. We will now consider some special cases.

**1)** $F=F_1(q,Q,t)$. This gives us
\$$ \dot{q}\_i p_i - \mathcal{H}(q, p, t) = \dot{Q}\_i P_i - \mathcal{K}(Q, P, t) + \frac{\partial F}{\partial q_i}\dot{q}\_i + \frac{\partial F}{\partial Q_i}\dot{Q}\_i + \frac{\partial F}{\partial t}. \$$
By comparing terms we can see that
\$$ p_i = \frac{\partial F_1}{\partial q_i} \$$
\$$ P_i = -\frac{\partial F_1}{\partial Q_i}. \$$
This leaves us with
\$$ \mathcal{K} = \mathcal{H} + \frac{\partial F_1}{\partial t}. \$$

How do we make use of such a function? We can use it to check, whether a given transformation is canonical, i.e. if it satisfies the above conditions. We can also come up with new generating functions and create new canonical transformations. To get the transformation equations from $F_1$, we can use the first equation, which gives us $p_i = p_i(q, Q, t)$ to solve for $Q$ and then use $P_i=P_i(q, Q, t)$.

**2)** Let us try a function of the form $F=F_2(q,P,t)$:
\$$ \dot{q}\_i p_i - \mathcal{H}(q, p, t) = \dot{Q}\_i P_i - \mathcal{K}(Q, P, t) + \frac{\partial F_2}{\partial q_i}\dot{q}\_i + \frac{\partial F_2}{\partial P_i}\dot{P}\_i + \frac{\partial F_2}{\partial t}. \$$
We run into trouble, though, as we have no matching terms for $\dot{P}\_i$ or $\dot{Q}\_i$. We will thus use a function of the form
\$$ F = F_2(q,P,t) + f, \$$
where $f$ is an unknown function, which will fill our gaps. We thus have:
\$$ \dot{q}\_i p_i - \mathcal{H}(q, p, t) = \dot{Q}\_i P_i - \mathcal{K}(Q, P, t) + \frac{\partial F}{\partial q_i}\dot{q}\_i + \frac{\partial F}{\partial p_i}\dot{p}\_i + \frac{\partial F}{\partial Q_i}\dot{Q}\_i + \frac{\partial F}{\partial P_i}\dot{P}\_i + \frac{\partial F}{\partial t}. \$$
We plug the definition of $F$ into the above equation, we compare terms and see that
\$$ \mathcal{K} = \mathcal{H} + \frac{\partial F_2}{\partial t} + \frac{\partial f}{\partial t}, \$$
so to keep it the same as for $F_1$, we must have $\partial f/\partial t=0$. Furthermore,
\$$ p_i = \frac{\partial F_2}{\partial q_i} + \frac{\partial f}{\partial q_i}, \$$
so we want $\partial f/\partial q_i=0$ for simplicity. We can also see that the only matching term with $\dot{Q}\_i$ will give us
\$$ P_i = - \frac{\partial F}{\partial Q_i} = - \frac{\partial f}{\partial Q_i}, \$$
which cannot be zero in general. There are no matching terms for $\dot{P}\_i$, so
\$$ \frac{\partial F}{\partial P_i}= \frac{\partial F_2}{\partial P_i}+ \frac{\partial f}{\partial P_i}=0. \$$
Due to symmetry between $(q,p)$ and $(Q, P)$, we choose that
\$$ Q_i = \frac{\partial F_2}{\partial P_i}, \$$
from which
\$$ \frac{\partial f}{\partial P_i} = -Q_i. \$$
We can thus see that $f=f(Q, P)$, where we got rid of $p$, because it changes completely nothing in the transformation (there are no derivatives w.r.t. it). From the partial derivatives we conclude that
\$$ f(Q,P) = -Q_i P_i. \$$
This means that for a generating function of the form
\$$ F = F_2(q,P,t) - Q_i P_i \$$
what follows is:
\$$ p_i = \frac{\partial F_2}{\partial q_i}, \$$
\$$ Q_i = \frac{\partial F_2}{\partial P_i}, \$$
\$$ \mathcal{K} = \mathcal{H} + \frac{\partial F_2}{\partial t}. \$$

**3)** We can repeat the same prodecure for a function $F_3(p, Q, t)$. In order to be able to match terms we must have $F=F_3(p,Q,t)+f(q,p,Q,P,t)$. We then discover that 
\$$ \frac{\partial f}{\partial q_i}=p_i, \$$
from which we have $f=q_i p_i+f_1(p,Q,P,t)$. We take $f_1$ to be independent of time, $p$ and $Q$, as those are already included in $F_3$. This leaves us with
\$$ \frac{\partial f}{\partial P_i} =0, \$$
so we have $F=F_3(p,Q,t)+p_i q_i$. The following equalities are then satisfied:
\$$ \mathcal{K} = \mathcal{H} + \frac{\partial F_3}{\partial t}, \$$
\$$ q_i = -\frac{\partial F_3}{\partial p_i}, \$$
\$$ P_i = -\frac{\partial F_3}{\partial Q_i}. \$$

**4)** The last type is $F=F_4(p,P,t)-Q_iP_i+q_ip_i$, so a combination of the previous ones (exactly, a Legendre transformation). As we can guess, we must have
\$$ \mathcal{K} = \mathcal{H} + \frac{\partial F_4}{\partial t}, \$$
\$$ q_i = -\frac{\partial F_4}{\partial p_i}, \$$
\$$ Q_i = \frac{\partial F_4}{\partial Q_i}. \$$


