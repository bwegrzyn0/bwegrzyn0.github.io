---
layout: post
title: "Wyznaczanie promienia oribty Jowisza"
date: 2026-02-08
categories: Astronomia
katex: true
---

Naszym celem jest wyznaczenie promienia oribty Jowisza na podstawie dwóch zdjęć, na których planeta ta jest widoczna na tle pobliskich gwiazd, wykonanych w odstępie nieco ponad roku.

<p align="center">
<img src="/assets/images/2026-02-08/23_11_2024.jpg" width="500" />
<img src="/assets/images/2026-02-08/05_02_2026.jpg" width="500" /> <br> <br>
<em> (a) Niebo dnia 23.11.2024 (b) Niebo dnia 05.02.2026 </em>
</p>

## Współrzędne równikowe i ekliptyczne Jowisza
Na zdjęciu a) Jowisz znajduje się tuż obok gwiazdy w niewielkim ,,trójkącie'' w gwiazdozbiorze Byka. Odnajdując tę gwiazdę w atlasie możemy z łatwością nanieść obok niej położenie planety i odczytać współrzędne równikowe, co daje
\$$ (\alpha_1, \delta_1) = (5^h07^m, 22\degree 24'). \$$

Na zdjęciu b) z łatwością odnajdujemy 2 pary gwiazd takie, że poprowadzone przez nie proste przecinają się w położeniu Jowisza: $\delta$ Gem i $\varepsilon$ Gem oraz $\zeta$ Gem i gwiazda leżąca pomiędzy $\delta$ Gem i $\iota$ Gem. Prowadząc wspomniane proste w atlasie i odczytując współrzędne punktu przecięcia otrzymujemy
\$$ (\alpha_2, \delta_2) = (7^h12^m, 22\degree 33'). \$$

<p align="center">
<img src="/assets/images/2026-02-08/atlas.jpg" width="700" /> <br>
<em>Fragment atlasu nieba z zaznaczonymi położeniami Jowisza</em>
</p>

<p align="center">
<img src="/assets/images/2026-01-28/sfer1.svg" width="500" /> <br> <br>
<em>BN - biegun niebieski, BE - biegun ekliptyczny</em>
</p>

Znając współrzędne równikowe Jowisza i korzystając z trójkąta paralaktycznego przedstawionego na powyższym rysunku, możemy wyznaczyć współrzędne ekliptyczne planety.

Z twierdzenia cosinusów:
\$$ \sin\beta=\cos\varepsilon\sin\delta-\sin\varepsilon\cos\delta\sin\alpha, \$$
a z twierdzenia sinusów:
\$$ \cos\lambda= \frac{\cos\alpha \cos\delta}{\cos\beta}. \$$

Wstawiając współrzędne równikowe otrzymujemy:
\$$ (\lambda_1, \beta_1) = (77.77\degree, -0.44\degree) \$$
oraz
\$$ (\lambda_2, \beta_2) = (106.58\degree, 0.18\degree). \$$

Widzimy, że szerokość ekliptyczna planety jest stale bliska $0\degree$, więc słuszne będzie przybliżenie, że jej oribta leży w płaszczyźnie ekliptyki.

## Promień oribty Jowisza
<p align="center">
<img src="/assets/images/2026-02-08/rys.svg" width="700" /> <br>
</p>
Założymy, że oribta Jowisza wokół Słońca jest okręgiem o promieniu $r_j$, a orbita Ziemi jest okręgiem o promieniu $r_z=1.0 \text{au}$. Dla trójkąta z powyższego rysunku możemy zapisać twierdzenie sinusów (kąt rozwarty trójkąta to $\pi-\lambda_j+\lambda_z-\pi$ - przenosimy kąt $\lambda_z-\pi$ jako wierzchołkowy, a następnie naprzemianległy):
\$$ \frac{\sin\theta}{d_j}= \frac{\sin(\lambda_z-\lambda_j)}{r_j} \$$ 
i twierdzenie cosinusów:
\$$ d_j = \sqrt{r_z^2+r_j^2-2r_z r_j\cos\theta}, \$$
skąd
\$$ \theta=\arcsin\left( \frac{\sqrt{r_z^2+r_j^2-2r_z r_j\cos\theta}}{r_j}\sin(\lambda_z-\lambda_j)\right). \$$
Równanie w powyższej postaci można łatwo rozwiązać iteracją prostą. Tak naprawdę mamy 2 równania, jedno dla każdej z dat. $\lambda_j$ znamy, potrzebujemy jedynie $\lambda_z$. Znając dzień roku, $t$, możemy wznaczyć $\lambda_z$ ze wzoru:
\$$ \lambda_z = \frac{2\pi}{365.25^d}(t-80^d), \$$
gdzie $80^d$ wynika z faktu, że równonoc wiosenna ma miejsce $80$-tego dnia roku. Brakuje nam jednego równania łączącego kąty $\theta_1$ i $\theta_2$ (dla poszczególnych dat) z $r_j$. Będzie to <a href="https://bwegrzyn0.github.io/mechanika/prawa-keplera" target=_blank>3 prawo Keplera</a>. Okres orbity Jowisza (w jednostkach au i yr) to
\$$ P_j=\sqrt{r_j^3}, \$$
a w czasie $\Delta t$ (pomiędzy wykonaniem zdjęć) Jowisz przebył kąt $\theta_2+\lambda_{z2}-180\degree-\theta_1-\lambda_{z1}+180\degree=\theta_2+\lambda_{z2}-\theta_1-\lambda_{z1}$. Stąd
\$$ \theta_2-\theta_1= \frac{2\pi}{P_j}\Delta t, \$$
więc
\$$ r_j = \sqrt[3]{\left( \frac{2\pi\Delta t}{\theta_2+\lambda_{z2}-\theta_1-\lambda_{z1}}\right)^2}. \$$
Wykonując iterację prostą kolejno tych trzech równań, $r_j$ powinno zbiegać do szukanej wartości.

### Implementacja algorytmu
Następujący kod w C++ wykonuje wyżej opisany algorytm:
```cpp 
float r_j = 1.0; // początkowa wartość dla r_j
float r_z = 1.0; // promień oribty Ziemi
float delta_t = 1.202; // odstęp czasu między 23.11.2024 a 05.02.2026
// (w latach, bo III prawo Keplera używa tych jednostek)
float t_1 = 327; // 23.11 - liczba dni po 1 stycznia
float t_2 = 36; // 05.02
float lambda_j1 = 77.77 * 3.1415 / 180; // długość ekliptyczna Jowisza dla odpowiednich dat
float lambda_j2 = 106.58 * 3.1415 / 180;

// początkowe wartości dla kątów
float theta_1 = 0;
float theta_2 = 0;

// iterujemy 10 razy, aby mieć pewność zbieżności
for(int i = 0; i < 10; i++) {
    // iterujemy kąty
    theta_1 = calc_theta(r_z, r_j, t_1, lambda_j1, theta_1);	
    theta_2 = calc_theta(r_z, r_j, t_2, lambda_j2, theta_2);	

    // obliczamy dłguość ekliptyczną Słońca z Ziemi 
    float lambda_z1 = clamp((t_1 - 80.0) * 2.0 * 3.1415 / 365.25);
    float lambda_z2 = clamp((t_2 - 80.0) * 2.0 * 3.1415 / 365.25);

    // obliczamy i wyświetlamy r_j
    r_j = pow(2 * 3.1415 * delta_t / (theta_2 + lambda_z2 - theta_1 - lambda_z1), 2.0);
    r_j = pow(r_j, 1.0/3.0);
    std::cout << r_j << "\n";
}
```
Funkcja `clamp()` ogranicza kąt do przedziału $\langle 0, 2\pi)$. Funkcja `calc_theta()` oblicza kąt zgodnie ze wcześniejszym wzorem:
```cpp
float calc_theta(float r_z, float r_j, float t, float lambda_j, float theta) {
    float lambda_z = clamp((t - 80.0) * 2.0 * 3.1415 / 365.25);
    float part1 = sqrt(1.0 + (r_z / r_j) * (r_z / r_j) - 2.0 * (r_z / r_j) * cos(theta));
    float part2 = sin(lambda_z - lambda_j);
    return asin(part1 * part2);
}
```

Wyjście programu prezentuje się następująco:
```
3.26988
4.66455
5.04167
5.11907
5.13377
5.13651
5.13702
5.13712
5.13714
```
Widzimy, że wynik zmierza do stabilnej wartości
\$$\boxed{r_j=5.14 \text{au}.}\$$
Dla porównania, <a href="https://en.wikipedia.org/wiki/Jupiter" target=_blank>literaturowa wartość</a> półosi wielkiej Jowisza to $5.2 \text{au}$. Na niewielką rozbieżność wyników wpływają oczywiście niepewność wyznaczenia współrzędnych planety oraz założenie o kołowości i współpłaszczyznowości orbit.
