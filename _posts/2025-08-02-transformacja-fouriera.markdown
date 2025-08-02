---
layout: post
title: "Transformacja Fouriera"
date: 2025-08-02
categories: ["Narzędzia matematyczne", Programowanie]
katex: true
---

## Szeregi Fouriera
Fourier zaproponował, że funkcje okresowe (tzn. $f(t)=f(t+\tau)$) spełniające dostateczne warunki (znaczna większość funkcji występujących w zastosowaniach je spełnia) można przedstawić w postaci __szeregu Fouriera__
\$$ f(t)=\sum_{n=0}^\infty a_n\cos\left(n\omega t\right)+b_n\sin\left(n\omega t\right), \$$
gdzie $\omega=2\pi/\tau$.
Wiadomo, że dowolna liniowa kombinacja sinusa i cosinusa to cosinus z przesunięciem fazowym, zatem
\$$ f(t)=\sum_{n=0}^\infty c_n\cos\left(n\omega t+\phi_n\right). \$$
Wygodniej jest operować na funkcji wykładniczej niż trygonometrycznej. Ponieważ $\cos x=(e^{ix}+e^{-ix})/2$, 
\$$ c_n\cos\left(n\omega t+\phi_n\right)=\frac{c_n}{2}\left(e^{i(n\omega_0 t+\phi_n)}+e^{-i(n\omega_0 t+\phi_n)}\right)=a_n e^{\phi_n}e^{in\omega_0 t}+a_{-n}e^{\phi_{-n}}e^{-in\omega_0 t}=\hat{a}\_n e^{in\omega_0 t}+\hat{a}\_{-n}e^{-in\omega_0 t} \$$
gdzie $a_n$ i $a_{-n}$ to pewne współczynniki. To pozwala nam zapisać
\$$ \boxed{f(t)=\sum_{n=-\infty}^\infty \hat{a}\_n e^{i n\omega t},} \$$
gdzie $n$ zaczyna się w $-\infty$, ponieważ musimy wziąć pod uwagę oba wyrazy.
Chcemy wyznaczyć współczynniki $\hat{a}\_n$. W tym celu pomnóżmy obie strony powyższej równości przez $e^{-i m\omega t}$, gdzie $m$ to liczba całkowita:
\$$ f(t)e^{-i m\omega t}=\sum_{n=-\infty}^\infty \hat{a}\_n e^{i n\omega t}e^{-i m\omega t}=\sum_{n=-\infty}^\infty \hat{a}\_n e^{i (n-m)\omega t} \$$
Pocałkujmy teraz obustronnie po czasie na przedziale $[0, \tau]$:
\$$ \int_0^\tau f(t)e^{-i m\omega t}\,dt=\sum_{n=0}^\infty\int_0^\tau\hat{a}\_n e^{i (n-m)\omega t}\,dt. \$$
Zajmijmy się całką wewnątrz sumy. Gdy $n=m$, całka ta wynosi $\hat{a}\_n\tau$, a w przeciwnym wypadku 
\$$ \int\_0^\tau\hat{a}\_n e^{i (n-m)\omega t}\,dt=\hat{a}\_n\left[\frac{1}{i\omega(n-m)}e^{i (n-m)\omega t}\right]\_0^\tau=\frac{\hat{a}\_n}{i\omega(n-m)}\left[e^{i(n-m)\cdot 2\pi}-1\right],\$$
gdzie skorzystałem z faktu, że $\omega\tau=2\pi$ oraz $e^0=1$. Zauważmy, że $2\pi(n-m)$ będzie __zawsze całkowitą wielokrotnością $2\pi$__, przez co $e^{i(n-m)\cdot 2\pi}=1$. Z tego powodu całka ta wynosić będzie 0. Ponieważ stwierdziliśmy, że wyrażenie pod sumą zeruje się dla $n\neq m$, pozostaje nam tylko $n=m$:
\$$ \int_0^\tau f(t)e^{-i n\omega t}\,dt=\tau\hat{a}\_n, \$$
a stąd
\$$ \boxed{\hat{a}\_n=\frac{1}{\tau}\int_0^\tau f(t)e^{-i n\omega t}\,dt.} \$$
$\hat{a}\_n$ są nazywane __współczynnikami Fouriera__.

### Przykład
Niech będzie dana funkcja opisująca falę kwadratową:
\$$ f(t) = \begin{cases}
1\quad t\in\left[n\tau, \left(n+\frac{1}{2}\right)\tau\right] \\\\ 0\quad\text{ dla innych } t,
\end{cases} \$$
gdzie $n$ to liczba całkowita. 

Zacznijmy od przypadku $n=0$, ponieważ wtedy funkcja wykładnicza pod całką wynosi $1$. Pozostawia to nas z
\$$ \hat{a}\_0=\frac{1}{\tau}\int_0^\tau f(t)\,dt=\frac{1}{\tau}\int_0^{\tau/2} \,dt=\frac{1}{2}, \$$
gdzie skorzystałem z faktu, że na przedziale $\left[0,\tau\right]$ $f(t)$ jest różne od $0$ tylko dla \$\left[0,\tau/2\right]$. Z tego samego faktu możemy skorzystać rozważając przypadek $n\neq 0$:
\$$ \hat{a}\_n=\frac{1}{\tau}\int_0^{\tau/2}e^{-i n\omega t}\,dt=-\frac{1}{\tau in\omega}\left[ e^{-i n\omega t}\right]\_0^{\tau/2}=-\frac{1}{\tau in\omega}\left[e^{-in\pi}-1\right]=-\frac{1}{2\pi in}\left[e^{-in\pi}-1\right].\$$
Dla $n$ parzystych $e^{-in\pi}=1$, a dla nieparzystych $-1$, zatem
\$$ \hat{a}\_n=\begin{cases}
\frac{1}{2}\quad n=0 \\\\ 0 \quad n \text{ parzyste} \\\\ \frac{1}{in\pi} \quad n\text{ nieparzyste}.
\end{cases} \$$
Współczynniki te dają nam szereg
\$$ f(t)=\frac{1}{2}+\frac{1}{i\pi}e^{i\omega t}-\frac{1}{i\pi}e^{-i\omega t}+\frac{1}{3i\pi}e^{3i\omega t}-\frac{1}{3i\pi}e^{-3i\omega t}+\dots, \$$
co po przekształceniach daje nam
\$$ f(t)=\frac{1}{2}+\frac{2}{\pi}\sin\omega t+\frac{2}{3\pi}\sin 3\omega t+\frac{2}{5\pi}\sin 5\omega t+\dots \$$
Wykres funkcji oraz pierwszych 3 i 10 wyrazów szeregu został umieszczony na poniższym rysunku.
<p align="center">
<img src="/assets/images/2025-08-02/falaKwadratowa.svg" width="700"/>
</p>

## Transformacja Fouriera 
Nie tylko funkcje okresowe można zapisać za pomocą sinusów i cosinusów. Dla funkcji, które nie są okresowe możemy przyjąć $\tau\to\infty$ oraz $2\pi/\tau\to d\omega$. Wtedy również $\hat{a}\_n\to \hat{a}(\omega)\,d\omega$. W granicy suma przechodzi w całkę i otrzymujemy
\$$ \boxed{f(t) = \int_{-\infty}^\infty \hat{a}(\omega)e^{i\omega t}\,d\omega} \$$
oraz 
\$$ \hat{a}(\omega)\,d\omega = \frac{d\omega}{2\pi}\int_0^\infty f(t)e^{-i\omega t}\,dt \$$
\$$ \boxed{\hat{a}(\omega) = \frac{1}{2\pi}\int_0^\infty f(t)e^{-i\omega t}\,dt}. \$$
Drugi wzór nosi nazwę __transformacji Fouriera__, a pierwszy __odwrotnej transformacji Fouriera__.

### Przykład
Rozważmy falę modulowaną przez funkcję Gaussa
\$$ f(t)=e^{-t^2/2\sigma^2}\cos \omega_0 t, \$$
której wykres dla róznych wartości $\sigma$ i $\omega_0$ przedstawiony jest poniżej. Widzimy, że zwiększając $\sigma$ ,,poszerzamy'' falę, a zwiększając $\omega_0$ zwiększamy częstotliwość.
<p align="center">
<img src="/assets/images/2025-08-02/falaModulowana.svg" width="700"/>
</p>
Aby znaleźć transformację Fouriera powyższej funkcji, zapiszymy $\cos$ w postaci zespolonej:
\$$ f(t)=\frac{1}{2}e^{-t^2/2\sigma^2}\left(e^{i\omega_0 t}+e^{-i\omega_0 t}\right) \$$
i wstawmy do wzoru na transformację
\$$ \hat{a}(\omega)=\frac{1}{2\pi}\int_{-\infty}^\infty f(t) e^{-i\omega t}\,dt=\frac{1}{4\pi} \int_{-\infty}^\infty e^{-t^2/2\sigma^2}e^{i\omega_0 t}e^{-i\omega t}+\frac{1}{4\pi}\int_{-\infty}^\infty e^{-t^2/2\sigma^2}e^{-i\omega_0 t}e^{-i\omega t}\,dt  \$$
Rozważmy teraz całkę
\$$ \int_{-\infty}^\infty e^{-t^2/2\sigma^2} e^{-i\omega' t}\,dt. \$$
W naszym przypadku dla pierwszej całki $\omega' =\omega-\omega_0$, a dla drugiej $\omega' =\omega+\omega_0$. Aby obliczyć powyższą całkę dopełnijmy kwadrat:
\$$ \int_{-\infty}^\infty e^{-t^2/2\sigma^2-i\omega' t}\,dt=\int_{-\infty}^\infty e^{-(t/\sqrt{2}\sigma+i\omega'\sigma/\sqrt{2})^2-\omega'^2\sigma^2/2}\,dt= \$$
\$$ =e^{-\omega'^2\sigma^2/2}\int_{-\infty}^\infty e^{-(t/\sqrt{2}\sigma+i\omega'\sigma/\sqrt{2})^2}\,dt. \$$
Podstawmy $u=t/\sqrt{2}\sigma+i\omega'\sigma/\sqrt{2}$, czyli $dt=\sqrt{2}\sigma\,du$. Granice całkowania pozostają niezmienione:
\$$ e^{-\omega'^2\sigma^2/2}\int_{-\infty}^\infty e^{-u^2}\sqrt{2}\sigma\,du = \sqrt{2\pi}\sigma e^{-\omega'^2\sigma^2/2}. \$$
Wstawmy ten wynik do wzoru na $\hat{a}$:
\$$ \hat{a}(\omega)=\frac{\sigma}{2\sqrt{2\pi}}\left(e^{-(\omega_0+\omega)^2\sigma^2/2}+e^{-(\omega_0-\omega)^2\sigma^2/2}\right) \$$
Powyższe wyrażenie można uprościć do
\$$ \hat{a}(\omega)=\frac{\sigma}{\sqrt{2\pi}}e^{-(\omega_0^2+\omega^2)\sigma^2/2}\cosh\left(\omega\omega_0\sigma^2\right). \$$
$\hat{a}$ możemy podnieść do kwadratu aby otrzymać __widmo mocy__ $S(\omega)$:
\$$ S(\omega)=\frac{\sigma^2}{2\pi}e^{-(\omega_0^2+\omega^2)\sigma^2}\cosh^2\left(\omega\omega_0\sigma^2\right). \$$
Zostało ono przedstawione dla wcześniejszych fal na poniższym wykresie:
<p align="center">
<img src="/assets/images/2025-08-02/widmoMocy.svg" width="700"/>
</p>
Jak widać, jest ono symetryczne względem osi $y$. Jest tak, ponieważ rozważane fale zawierają tylko składową parzystą $\cos$. Dla funkcji $\cos$ nie ma znaczenia znak częstotliwości, a więc moc jest rozłożona równomiernie między $\omega$ i $-\omega$. Zgodnie z oczekiwaniami najwięcej mocy jest skupionej w częstotliwości $\omega_0$. Zauważmy również, że im bardziej ,,rozwlekła'' fala, tym bardziej moc jest skupiona wokół $\omega_0$ (czerwony wykres). Jest to spodwodowane faktem, że bardziej ,,rozwlekła'' fala bardziej ,,przypomina'' zwykłą falę.
