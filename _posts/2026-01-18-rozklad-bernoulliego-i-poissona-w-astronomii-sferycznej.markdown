---
layout: post
title: "Rozkład Bernoulliego i Poissona w astronomii sferycznej"
date: 2026-01-18
categories: Astronomia
katex: true
---

## Rozkład Bernoulliego (dwumianowy)
Najprostszym przykładem ilustrującym ten rozkład jest rzut monetą. Niech prawdopodobieństwo wyrzucenia reszki wynosi $p$, a prawdopodobieństwo wyrzucenia orła - $1-p$ (jeśli $p=1/2$, moneta jest ,,uczciwa'', a w przeciwnym przypadku jest ,,stronnicza''). Niech będzie w sumie $N$ rzutów. Interesuje nas prawdopodobieństwo wyrzucenia reszki $k$ razy.

Rozważmy pewną sekwencję rzutów (permutację), w której reszka wypadła $k$ razy. Prawdopodobieństwo, że reszka wypadnie dokładnie $k$ razy, a orzeł dokładnie $N-k$ (bo suma rzutów to $N$) to z podstawowego rachunku prawdopodobieństwa
\$$ p^k(1-p)^{N-k}. \$$
Jest to prawdobodobieństwo, że trafiona przez nas sekwencja rzutów ma akurat $k$ reszek i $N-k$ orłów. Wszystkich takich możliwych sekwencji jest tyle, na ile sposobów możemy wybrać $k$ rzutów z $N$ rzutów, czyli
\$$ {N\choose k}. \$$
Z tego powodu całkowite prawdopodobieństwo zwiększa się o ten czynnik. Wynosi ono:
\$$ \boxed{p_k = {N\choose k} p^k (1-p)^{N-k}.} \$$
Jest to szukany przez nas **rozkład dwumianowy (Bernoulliego)**.

### Przykładowe zastosowanie w astronomii
**Problem:** Na niebie jest około $6000$ gwiazd widocznych gołym okiem. Jakie jest prawdopodobieństwo, że tylko dwie z nich znajdą się nie dalej niż $10''$ (sekund kątowych)? Zakładamy, że gwiazdy są rozmieszone na całej sferze niebieskiej losowo i niezależnie od siebie oraz nie są związane fizycznie. (32 OA, II etap, zadanie 2) 

W tym przypadku nasz jeden rzut monetą to sprawdzenie jednej pary gwiazd, a wylosowanie reszki to ich wzajemne położenie bliższe niż $10''$. Wyznaczmy najpierw prawdopodobieństwo, że dwie gwiazdy znajdą się w odległości mniejszej niż $10''$. Kąt bryłowy opisany przez stożek o kącie rozwarcia $\theta$ (w radianach) to
\$$ \Omega=2\pi(1-\cos\theta)\approx \pi\theta^2, \$$
gdzie przybliżenie jest prawdziwe, jeśli $\theta$ jest małe. $10''$ jest o wiele mniejsze niż $1$ rad, więc przybliżenie będzie słuszne. Cała sfera niebieska obejmuje kąt $4\pi$, więc szukane prawdopodobieństwo to
\$$ p= \frac{\Omega}{4\pi}= \frac{\theta^2}{4}. \$$
Wstawiając dane otrzymujemy 
\$$ p\approx 5.9 \times 10^{-10}. \$$
Wszystkich par na niebie jest 
\$$ N_2={6000\choose 2}= \frac{6000!}{2!\cdot 5998!}= \frac{6000\cdot5999}{2}\approx \frac{6000^2}{2}=1.8 \times 10^{7}. \$$
Wstawiając to wszystko do rozkładu Bernoulliego z $k=1$ (tylko jedna para) dostajemy
\$$ p_1 = N_2 p (1-p)^{N_2-1} \$$
(${N_2\choose 1}=N_2$).
Ponieważ $p$ jest małe, możemy przybliżyć $(1+x)^\alpha\approx 1+\alpha x$, $N_2-1\approx N_2$:
\$$ p_1 \approx N_2 p(1-N_2p). \$$
Wstawiając dane liczbowe dostajemy
\$$ p_1\approx 1.1\%. \$$

## Rozkład Poissona
W tym przypadku postać tego rozkładu będzie motywowana następującym problemem.

**Problem:** Pewnej nocy prowadzono obserwacje meteorów. W kącie bryłowym o rozwarciu $45\degree$ w otoczeniu zenitu w ciągu godziny zaobserwowano średnio $n=6$ meteorów. Zakładając, że rozbłysk meteoru jest zjawiskiem losowym zachodzącym z tym samym prawdopodobieństwem dla całej sfery niebieskiej, oblicz prawdopodobieństwo, że w ciągu godziny w podanym kącie bryłowym a) pojawi się co najmniej jeden meteor, b) nie pojawi się żaden, c) pojawi się ich dokładnie 6. (30 OA, II etap, zadanie 2)

Podzielmy czas $t=1$h na $N$ interwałów o długości $\Delta t=t/N$ każdy. Załóżmy, że jak $N\to\infty$, prawdopodobieństwo, że w ciągu tego samego interwału zajdą 2 rozbłyski meteoru jest pomijalnie małe. Oznacza to, że ponownie mamy rzut monetą, tym razem dla rozbłysków. Niech prawdopodobieństwo, że rozbłysk zajdzie w rozpatrywanym kącie bryłowym w interwale $\Delta t$ wynosi $p$. Interwałów czasu mamy $N$, czyli $N$ ,,rzutów'', a rozbłysków niech będzie $k$. Wstawiając to do rozkładu Bernoulliego otrzymujemy prawdopodobieństwo, że w czasie $t$ w rozpatrywanym kącie bryłowym zajdzie dokładnie $k$ rozbłysków:
\$$ p_k= {N\choose k} p^k (1-p)^{N-k}. \$$
Weźmy teraz granicę jak $N\to\infty$, czyli przedziały czasu $\Delta t$ stają się bardzo małe oraz $k\ll N$ (stąd $N-k\approx N$). Jeśli rozpiszemy symbol Newtona otrzymamy:
\$$ {N\choose k}= \frac{N(N-1)\cdots (N-k+1)}{k!} \approx \frac{N^k}{k!}, \$$
bo $k\ll N$. 

Zajmiemy się teraz prawdopodobieństwem. Ponieważ każdy interwał czasu jest równy i rozbłyski są w pełni losowe, prawdopodobieństwo, że rozbłysk zajdzie akurat w tym interwale w kącie bryłowym $\Omega$ to
\$$ p = \frac{n}{N}, \$$ 
gdzie, jak pamiętamy, $n$ to średnia liczba rozbłysków na godzinę. Wstawiając to do rozkładu otrzymujemy
\$$ p_k\approx \frac{N^k}{k!} \frac{n^k}{N^k}(1-p)^N= \frac{ n^k}{k!}(1-\frac{n}{N})^N.\$$
Ponieważ $N\to\infty$, wyrażenie w nawiasie z potęgą rozpozajemy jako jedną z definicji $e^{-n}$, zatem:
\$$ p_k= \frac{n^k}{k!}e^{-n}. \$$
Prawdopodobieństwo z podpunktu a) to $1-P(\text{nie pojawi się żaden meteor})=1-p_0$, czyli
\$$ p_a=1-e^{-6}=99.75\%. \$$
Od razu wynika stąd odpowiedź do podpunktu b), $p_b=0.25\%$. Dla podpunktu c):
\$$ p_c=p_6\approx 16\%. $$

Jak wyprowadziliśmy wyżej na przykładzie, **rozkład Poissona**, opisujący prawdopodobieństwo zajścia $k$ wydarzeń, które zachodzą z pewną średnią częstością $\lambda$ w pewnym interwale czasu, w tym interwale to
\$$ \boxed{p_k = \frac{\lambda^k}{k!}e^{-\lambda}.} \$$
