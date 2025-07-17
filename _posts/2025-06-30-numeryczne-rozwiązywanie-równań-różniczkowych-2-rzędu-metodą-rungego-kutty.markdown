---
layout: post
title: "Numeryczne rozwiązywanie równań różniczkowych 2 rzędu za pomocą algorytmu Rungego-Kutty"
date: 2025-06-30
categories: [Programowanie]
katex: true
---

## Algorytm Rungego-Kutty
Mamy dane równanie różniczkowe 1 rzędu w postaci
\$$ \frac{dy}{dx}=f(x,y). \$$
Najprostszą metodą, aby rozwiązać tego typu równanie numerycznie jest metoda Eulera. Pochodną możemy przybliżyć jako
\$$ \frac{dy}{dx}\approx\frac{y(x+\Delta x)-y(x)}{\Delta x}, \$$
a stąd
\$$ y(x+\Delta x)\approx y(x)+\Delta x f(x,y). \$$
Metoda ta jest bardzo niedokładna szczególnie dla rozwiązań oscylujących. Jest ona również nazywana algorytmem Rungego-Kutty 1 rzędu. 

O wiele lepsze przybliżenie daje algorytm Rungego-Kutty 4 rzędu. W pierwszej kolejności należy obliczyć 4 wielkości:
\$$ k_1=f(x,y) \$$
\$$ k_2=f(x+\frac{\Delta x}{2}, y+\frac{\Delta x}{2}k_1) \$$
\$$ k_3=f(x+\frac{\Delta x}{2}, y+\frac{\Delta x}{2}k_2) \$$
\$$ k_4=f(x+\Delta x, y+\Delta x\,k_3), \$$
a następnie możemy obliczyć wartość szukanej funkcji w kolejnym kroku:
\$$ y(x+\Delta x)\approx y(x)+\frac{\Delta x}{6}(k_1+2k_2+2k_3+k_4). \$$
### Przykład
Rozważmy równanie nieliniowe
\$$ \frac{dy}{dx}=y\cos x\$$
z warunkiem początkowym \$ y(0)=1 \$. Łatwo jest sprawdzić, że jego rozwiązaniem jest \$ y=e^{\sin x}\$.

Program rozwiązujący to równanie numerycznie został napisany w C++.

W pierwszej kolejności definiujemy zmienne i warunki początkowe:
```cpp
float y = 1; // ustawiamy y na wartość początkową
float x = 0; // ustawiamy x na wartość początkową
float x_max = 30; // końcowa wartość x
float step = 0.5; // krok - Delta x
```

Następnie zdefiniujmy naszą funkcję $f(x,y)$:
```cpp
float dy_dx(float y, float x) {
	return y*cos(x);
}
```

Teraz musimy wykonać `(x_max-x_min)/step` kroków, a w każdym z nich wykonać procedurę opisaną na początku artykułu:
```cpp
for (int i = 1; i < (x_max-x_min)/step; i++) {
		float k_1 = dy_dx(y, x);
		float k_2 = dy_dx(y+step/2*k_1, x+step/2);
		float k_3 = dy_dx(y+step/2*k_2, x+step/2);
		float k_4 = dy_dx(y+step*k_3, x+step);

		x += step; // zwiększamy x o jeden krok
		y += step/6*(k_1+2*k_2+2*k_3+k_4); // obliczamy y(x+Delta x)
		file << x << ", " << y << "\n"; // zapisujemy wynik do pliku 
}
```

Wyniki zapisałem do pliku `.csv`, a następnie naniosłem w pythonie na widoczny poniżej wykres:

<p align="center">
<img src="/assets/images/2025-06-30/przyklad1.svg" width="500" />
</p>
Czerwona linia przedstawia rozwiązanie analityczne, a niebieskie krzyżyki rozwiązanie numeryczne. Widzimy, że algorytm Rungego-Kutty 4 rzędu nawet przy dużych wartościach \$ \Delta x \$ daje bardzo dobre rezultaty. 

## Równanie różniczkowe 2 rzędu jako układ równań 1 rzędu
Niech będzie dane równanie różniczkowe 2 rzędu:
\$$ \frac{d^2 y}{dx^2}=f(x, y, y'). \$$
Podstawienie \$ u=y' \$ daje nam układ równań pierwszego rzędu
\$$
\begin{cases} u' = f(x, y, u) \\\\ u=y'=g(x,y,u) \end{cases} 
\$$

### Przykład
Rozważmy równanie ruchu tłumionego oscylatora harmonicznego:
\$$ \ddot{x}+2\beta m\dot{x}+\omega_0^2 x = 0. \$$
Podstawienie $v=\dot{x}$ daje nam układ równań
\$$
\begin{cases} \dot{v}=-2\beta v-\omega_0^2 x \\\\ v=\dot{x}  \end{cases}
\$$

## Numeryczne rozwiązywanie równań 2 rzędu
Aby numerycznie rozwiązać równanie 2 rzędu musimy mieć dane $y(x_0)$ oraz $u(x_0)$, gdzie $x_0$ to pewna wartość początkowa zmiennej.

W pierwszej kolejności obliczamy $k_1$ dla obydwu równań:
\$$ k_{1y}=g(x, y, u), \$$
gdzie $g(x, y, u)=u$.
\$$ k_{1u}=f(x, y, u) \$$
Aby obliczyć $k_{2y}$, za $u$ podstawiamy $u+k_{1u}\Delta x/2$:
\$$ k_{2y}=g(x+\frac{\Delta x}{2}, y+k_{1y}\frac{\Delta x}{2}, u+k_{1u}\frac{\Delta x}{2}) \$$
i podobnie obliczamy $k_{2u}$:
\$$ k_{2u}=f(x+\frac{\Delta x}{2}, y+k_{1y}\frac{\Delta x}{2}, u+k_{1u}\frac{\Delta x}{2}). \$$
Prodecura wygląda analogicznie dla $k_3$ i $k_4$. Finalnie możemy obliczyć $y(x+\Delta x)$:
\$$ y(x+\Delta x)=y(x)+\frac{\Delta x}{6}(k_{1y}+2k_{2y}+2k_{3y}+k_{4y}) \$$
i analogicznie $u$.

### Przykład
Rozważmy wcześniejsze równanie ruchu tłumionego oscylatora harmonicznego z warunkami początkowymi $x(0)=0$ i $v(0)=1$ oraz parametrami $\omega_0=2$, $\beta=0.5$, $m=1$.

Zdefiniujmy zmienne i warunki początkowe:
```cpp
// warunki początkowe
float x = 0;
float v = 1;
float t_min = 0;
float t = t_min;
float t_max = 10; // jak daleko ma sięgać symulacja
float step = 0.2; // Delta x
// parametry układu
float omega_0 = 2;
float beta = 0.5;
```
Następnie zdefiniujmy funkcje $f(x)$ i $g(x)$:
```cpp
// funkcja obliczająca dv/dt
float f(float t, float x, float v) {
	return -2*beta*m*v-omega_0*omega_0*x;
}

// funkcja obliczająca dx/dt
float g(float t, float x, float v) {
	return v;
}
```
Utwórzmy funkcję, która oblicza kolejne wartości $x$ i $v$:
```cpp
// funkcja obliczająca następną wartość x  z użyciem metody Rungego-Kutty
void next(float t, float x, float v) {
	// obliczamy wszystkie k dla obu równań
	float k_1x = g(t, x, v);
	float k_1v = f(t, x, v);

	float k_2x = g(t+step/2, x+k_1x*step/2, v+k_1v*step/2);
	float k_2v = f(t+step/2, x+k_1x*step/2, v+k_1v*step/2);

	float k_3x = g(t+step/2, x+k_2x*step/2, v+k_2v*step/2);
	float k_3v = f(t+step/2, x+k_2x*step/2, v+k_2v*step/2);

	float k_4x = g(t+step, x+k_3x*step, v+k_3v*step);
	float k_4v = f(t+step, x+k_3x*step, v+k_3v*step);
	
	// obliczamy kolejne wartości dla x oraz v
	::x += step/6*(k_1x+2*k_2x+2*k_3x+k_4x);
	::v += step/6*(k_1v+2*k_2v+2*k_3v+k_4v);
}
```
Należy pamiętać, aby również obliczać kolejne wartości dla $v$, ponieważ w przeciwnym razie pochodna będzie cały czas stała. Możemy teraz utworzyć pętlę w funkcji `main()`:
```cpp
for (int i = 1; i < (t_max-t_min)/step; i++) {
    t += step;
    next(t, x, v);
    file << t << ", " << x << ", " << v <<  "\n"; // zapisujemy wyniki do pliku
}
```
Podobnie jak wcześniej wyniki oraz rozwiązanie analityczne naniosłem na jeden wykres, otrzymując idealną zgodność:
<p align="center">
<img src="/assets/images/2025-06-30/przyklad2.svg" width="500" />
</p>

Pełne pliki źródłowe są dostępne do pobrania tutaj: \\
<a href="/assets/downloads/2025-06-30/przykład1.cpp" target="_blank">przykład1.cpp</a> \\
<a href="/assets/downloads/2025-06-30/przykład2.cpp" target="_blank">przykład2.cpp</a>

## Uogólnienie na równania wyższych rzędów
W takim przypadku ponownie rozpisujemy równanie $n$-tego rzędu jako układ $n$ równań różniczkowych 1 rzędu, np.
\$$
\begin{cases} \dot{x_1}=f_1(t, x_1, x_2, \dots, x_n) \\\\ \dot{x_2}=f_2(t, x_1, x_2, \dots, x_n) \\\\ \dots \\\\ \dot{x_n}=f_n(t, x_1, x_2, \dots, x_n) \end{cases}
\$$
Niech $\mathbf{x}=(x_1,x_2,\dots,x_n)^\intercal$ oraz $\mathbf{f}(t, \mathbf{x})=(f_1(t, \mathbf{x}), f_2(t, \mathbf{x}), \dots, f_n(t, \mathbf{x}))^\intercal$. Wtedy układ równań możemy zapisać jako 
\$$ \dot{\mathbf{x}}=\mathbf{f}(t, \mathbf{x}) \$$
Obliczamy teraz $\mathbf{k_1}, \mathbf{k_2}, \dots$:
\$$ \mathbf{k_1}=\mathbf{f}(t, \mathbf{x}) \$$
\$$ \mathbf{k_2}=\mathbf{f}(t+\frac{\Delta t}{2}, \mathbf{x}+\mathbf{k_1}\frac{\Delta t}{2}) \$$
itd.
W przypadku $n=2$ wszystko sprowadza się do opisanego wcześniej algorytmu.
