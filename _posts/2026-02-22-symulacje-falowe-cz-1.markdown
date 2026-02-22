---
layout: post
title: "Symulacje falowe, część 1"
date: 2026-02-22 
categories: Programowanie 
katex: true
---

## Równanie falowe
Rozważmy $N$ mas $m$ połączonych $N-1$ sprężynkami o współczynniku sprężystości $k$ i długości swobodnej $x_0$. Jeśli sprężyny są sztywne, może być to np. model sztywnego pręta. Wyznaczymy teraz prędkość rozchodzenia się zaburzeń w tym układzie i równanie je opisujące.

Rozważmy siły działające na $i$-tą masę. Niech $u_i$ oznacza jej wychylenie z położenia równowagi, dodatnie w prawo, a $x_i$ odległość jej położenia równowagi od początku pręta. Siła pochodząca od sprężyny z prawej strony to
\$$ F_1=-k(u_i-u_{i+1}), \$$
a siła pochodząca od tej z lewej to
\$$ F_2=-k(u_i-u_{i-1}), \$$
więc
\$$ m\ddot{u}\_i=F_1+F_2=k(u_{i+1}-2u_i+u_{i-1}). \$$
Załóżmy, że $N$ jest duże, czyli $m$ oraz wszystkie $u$ są małe. Zauważmy, że wyrażenie w nawiasie przypomina wzór na drugą pochodną:
\$$ \frac{d^2 y}{dx^2}= \frac{y(x+dx)-2y(x)+y(x-dx)}{dx^2}, \$$
gdzie u nas $y\rightarrow u$, a $x$ to również $x$. Mamy:
\$$ m\ddot{u}= k\frac{\partial^2 u}{\partial x^2}u_0^2, \$$
gdzie mamy pochodną cząstkową, ponieważ $u$ to również funkcja czasu oraz $u_0$, ponieważ jest ono równe $x_{i+1}-x_i$. Pochodna $u$ po czasie to:
\$$ \frac{du}{dt}= \frac{\partial u}{\partial t}+ \frac{\partial u}{\partial x} \frac{dx}{dt}, \$$
ale położenie równowagi każdej masy jest ustalone, więc pozostaje tylko pierwszy człon. Stąd mamy
\$$ \frac{\partial^2 u}{\partial^2 t}= \frac{k u_0^2}{m} \frac{\partial^2 u}{\partial x^2}. \$$
Niech $M=Nm$ oznacza całkowitą masę pręta, a $L=u_0 N$ jego długość. Mamy wtedy
\$$ \frac{k u_0^2}{m}= \frac{k L^2}{N M}. \$$
Sprężyny są pewną analogią do kondensatorów, ponieważ połączone ,,szeregowo'' dają zastępczy współczynnik spręzystości równy
\$$ \frac{1}{k_z}=\sum_i \frac{1}{k_i}. \$$
U nas $k_i=k$, więc współczynnik sprężytości całego pręta to $K=k/N$, więc ostatecznie:
\$$ \frac{\partial^2 u}{\partial t^2}= \frac{KL^2}{M} \frac{\partial u^2}{\partial x^2}. \$$    
Jest to **równanie falowe**, które w najogólniejszej postaci dla 1 wymiaru ma postać:
\$$ \boxed{\frac{\partial^2 u}{\partial t^2}= c^2 \frac{\partial^2 u}{\partial x^2},} \$$
gdzie $c$ to prędkość rozchodzenia się fal w ośrodku. Widzimy zatem, że dla pręta
\$$ c=\sqrt{ \frac{KL^2}{M}}. \$$

Podobne rozumowanie możemy przeprowadzić dla większej liczby wymiarów, np. dla dwóch:
\$$ \frac{\partial u}{\partial t^2}= c^2\left( \frac{\partial^2 u}{\partial x^2}+  \frac{\partial^2 u}{\partial y^2}\right) \$$
lub w ogólności:
\$$ \boxed{\frac{\partial u}{\partial t^2}= c^2\nabla^2 u.} \$$
W tym artykule zajmiemy się równaniem falowym dla dwóch wymiarów.

## Numeryczne rozwiązywanie równania falowego
Aby numerycznie rozwiązać równianie falowe w dwóch wymiarach, utworzymy tablicę dwuwymiarową $N\times N$ reprezentującą siatkę komórek o wymiarach $\Delta x\times\Delta x$. Komórka $(i,j)$ ma przypisaną wartość $u_{ij}$. Do obliczenia drugich pochodnych w przestrzeni wykorzystamy dobrze znany wzór:
\$$ \frac{\partial^2 u_{ij}}{\partial x^2}\approx \frac{u_{(i+1)j}-2u_{ij}+u_{(i-1)j}}{\Delta x^2} \$$
i podobnie dla pochodnej po $y$. Dla pochodnych czasowych:
\$$ \frac{\partial^2 u_{ij}}{\partial t^2} \approx \frac{u_{ij}(t+\Delta t)-2u_{ij}(t)+u_{ij}(t-\Delta t)}{\Delta t^2}. \$$
Wstawiając do równania falowego, mamy
\$$ \frac{u_{ij}(t+\Delta t)-2u_{ij}(t)+u_{ij}(t-\Delta t)}{\Delta t^2}=c^2\left(\frac{\partial^2 u_{ij}}{\partial x^2}+\frac{\partial^2 u_{ij}}{\partial y^2}\right), \$$
co, aby obliczyć $u_{ij}(t+\Delta t)$, przekształcamy do postaci:
\$$ u_{ij}(t+\Delta t)=c^2\Delta t^2\left(\frac{\partial^2 u_{ij}}{\partial x^2}+\frac{\partial^2 u_{ij}}{\partial y^2}\right)+2u_{ij}(t)-u_{ij}(t-\Delta t). \$$
Zauważmy, że potrzebujemy zapisywać w pamięci również $u_{ij}(t-\Delta t)$.

Napotykamy jednak problem związany z brzegami obszaru. W tym artykule założymy, że $u$ zawsze $=0$ na brzegach, co ma efekt podobny do ściany - fale będą się od nich odbijać. W drugiej części artykułu zaimplementujemy warunki brzegowe, które będą absorbować fale, co da nam efekt fali opuszczającej obszar. Z tego powodu tablica w programie będzie miała tak naprawdę wymiary $(N+2)\times(N+2)$, aby pomieścić również brzegi.

### Implementacja w C++
```cpp
double t = 0.0;
const int size_x = 100, size_y = 100;
double u[size_x+2][size_y+2];
double old_u[size_x+2][size_y+2];
double c = 1.0;
double dx = 1.0;
double dt = 0.1;

void calculate_u() {
    double new_u[size_x+2][size_y+2]; 
    std::memset(new_u, 0, sizeof new_u);

    for (int i = 1; i < size_x+1; i++){
        for (int j = 1; j < size_y+1; j++) {
            double d2u_dx2 = (u[i+1][j] - 2*u[i][j] + u[i-1][j])/(dx*dx);
            double d2u_dy2 = (u[i][j+1] - 2*u[i][j] + u[i][j-1])/(dx*dx);
            new_u[i][j] = c*c*dt*dt * (d2u_dx2 + d2u_dy2) + 2*u[i][j] - old_u[i][j];
        }
    }

    std::swap(old_u, u);
    std::swap(u, new_u);
}
```
Na początku programu tworzymy potrzebne zmienne i tablice (czas, $u$ i $u$ z poprzedniej iteracji), ustalamy rozmiary symulacji (`size_x` i `size_y`, `dx` to krok w przestrzeni - ten sam dla $x$ i $y$, a `dt` to krok w czasie) i jej parametry (`c` - prędkość fali). W funkcji `calculate_u()` tworzymy pustą tablicę, do której obliczmy nowe wartości $u$ dla wszystkich komórek (nie możemy modyfikować $u$, ponieważ później używalibyśmy nowych, a nie aktualnych wartości do obliczeń). Po obliczeniach zapisujemy stare wartości (potrzebne do symulacji) do tablicy `old_u`, a nowe wartości do `u`.

```cpp
int main() {
	std::memset(old_u, 0, sizeof old_u);
	std::memset(u, 0, sizeof u);

	u[5][5] = 1.0;
	old_u[5][5] = 1.0;

	std::ofstream data;
	data.open("data.csv");

	for (int i = 0; i < 500; i++) {
		calculate_u();
		t += dt;
		for (int i = 0; i < size_x + 2; i++) {
			for (int j = 0; j < size_y + 2; j++)
				if (j != size_y + 1)
					data << u[i][j] << ", ";
				else
					data << u[i][j];
			data << "\n";
		}
	}
	data.close();
	return 0;
}
```

W funkcji `main` inicjalizujemy tablice `u` i `old_u`, dodajemy chwilowe zaburzenie w $(5,5)$, a następnie dla 500 kroków w czasie iterujemy algorytm i wyniki zapisujemy w pliku `.csv`. Korzystając z biblioteki `matplotlib` w pythonie możemy wyniki obliczeń zwizualizować w postaci animacji:
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-02-23/anim5.mp4" type="video/mp4">
</video>
</p>

Aby działo się coś więcej, możemy dodać na środku siatki 2 źródła oscylujące w zgodnej fazie. W pętli `for` przed `calculate_u()` dodajemy:
```cpp
u[45][50] = sin(t);
u[55][50] = sin(t);
```
Efekt jest następujący.
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-02-23/anim2.mp4" type="video/mp4">
</video>
</p>
Widzimy wyraźne tworzenie się minimów interferencyjnych. Ze wzoru na interferencję na dwóch szczelinach pierwsze minimum powinno być pod kątem:
\$$ \alpha= \arcsin \frac{\lambda}{d}. \$$
U nas $d=10$, a $\lambda=c/f$. $c=1$ (ustalone w programie), a $f$ możemy obliczyć ze wzoru $\omega/2\pi$. U nas $\omega=1$, bo mamy $\sin t$. Stąd $\lambda=2\pi$ oraz $\alpha\approx 40\deg$. Bardzo podobny kąt odczytujemy również z animacji.

Dodając w pętli `for` w funkcji `calculate_u()` warunek
```cpp
if (i == 50 && (j <= 47 || j >= 53))
    continue;
```
możemy utworzyć po środku obszaru ścianę z przesłoną:
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-02-23/anim1.mp4" type="video/mp4">
</video>
</p>
Wyraźnie widzimy zjawisko ugięcia na szczelinie. Widzimy również wadę przyjętych warunków brzegowych - fale odbijają się od ścian i coraz bardziej się wzmacniają tworząc fale stojące (na brzegach) i ciekawe wzory. 

W ścianie umieścimy również dwie szczeliny:
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-02-23/anim3.mp4" type="video/mp4">
</video>
</p>
i widzimy dobrze znane prążki. Szczeliny możemy również umiejscowić w różnych odległościach od źródła, aby zmienić fazę w każdej ze szczelin:
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-02-23/anim4.mp4" type="video/mp4">
</video>
</p>
Fale w każdej ze szczelin są w przybliżeniu w przeciwfazie, a ta wychodząca z dolnej szczeliny ma większą amplitudę, ponieważ jest bliżej źródła. Prążki nie są teraz idealnie równe.

Nasze warunki brzegowe można jednak wykorzystać na własną korzyść, tworząc np. okrągłą ścianę i tak dobierając parametry, aby powstała fala stojąca:
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-02-23/anim6.mp4" type="video/mp4">
</video>
</p>
Fala stojąca po chwili zanika, a potem ponownie się pojawi, ponieważ ze względu na skończoną prezycję, parametrów nie można dobrać idealnie i będą zachodzić dudnienia.
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-02-23/anim7.mp4" type="video/mp4">
</video>
</p>
Możemy zrobić również animację 3d:
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-02-23/anim8.mp4" type="video/mp4">
</video>
</p>
