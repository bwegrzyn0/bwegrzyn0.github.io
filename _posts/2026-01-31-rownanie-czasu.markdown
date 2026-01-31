---
layout: post
title: "Równanie czasu"
date: 2026-01-31
categories: [Astronomia sferyczna]
katex: true
---

## Motywacja
Okazuje się, że Słońce nie porusza się w ciągu roku po ekliptyce ze stałą prędkością. Wynika to głównie z dwóch czynników: nachylenia ekliptyki oraz ekscentryczności orbity Ziemi. Ponieważ zegary nie są w stanie mierzyć zmiennego czasu, wprowadzono pojęcie **Słońca średniego** (ang. *mean Sun*), czyli punktu, który porusza się po *równiku* niebieskim ze stałą prędkością, zakreślając kąt $360\degree$ w ciągu roku zwrotnikowego (od równonocy do równonocy). Kąt godzinny Słońca średniego to czas wskazywany przez nasze zegarki (minus $12^h$ bo $h=0^h$ w chwili górowania). Różnicę między kątem godzinnym Słońca średniego (MS) i Słońca prawdziwego (TS - od *true Sun*), czyli między czasem Słonecznym średnim a prawdziwym wyraża **równanie czasu**:
\$$ \boxed{\tau=h_{MS}-h_{TS}.} \$$
W tym artykule wyprowadzimy przybliżone równanie czasu dla Ziemi, zakładając, że zarówno nachylenie ekliptyki, jak i ekscentryczność orbity są na tyle małe, że zezwalają na pewne przybliżenia, które znacznie uproszczą wzory. Wcześniej jednak, przekształcimy równanie czasu korzystając z zależności $\Theta=\alpha+h$, gdzie $\Theta$ to lokalny czas gwiazdowy, a $\alpha$ to rektascencja obiektu o kącie godzinnym $h$:
\$$ \tau=\alpha_{TS}-\alpha_{TS}. \$$

## Wkład nachylenia ekliptyki
<p align="center">
<img src="/assets/images/2026-01-31/rys1.svg" width="500" />
</p>
Korzystając z prostokątego trójkąta sferycznego przedstawionego schematycznie na powyższym rysunku, koła Napiera i reguły SIN-TAAD, otrzymujemy zależność
\$$ \cos\varepsilon=\cot\lambda_{TS}\tan\alpha_{TS} \rightarrow \alpha_{TS}=\arctan\left(\cos\varepsilon\tan\lambda_{TS}\right), \$$
gdzie $\varepsilon$ oznacza nachylenie ekliptyki, a poprzez $\lambda$ będziemy oznaczać zawsze długość ekliptyczną (mierzoną od punktu Barana, w tym samym kierunku, co rektascensja). 

$\varepsilon=23\degree 26'$, a $\cos$ tego kąta jest bardzo bliski $1$. Możemy zapisać więc $\cos\varepsilon$ jako $1-\delta$, gdzie $\delta$ jest małą liczbą. W ogólnym przypadku:
\$$ \arctan((1-\delta)x)=\arctan(x-x\delta), \$$
a poniewaz $\delta\ll 1$, to $x\delta \ll x$, więc możemy przybliżyć wyrażenie jako
\$$ \arctan(x-x\delta)\approx \arctan x- x\delta\frac{d}{dx}(\arctan x). \$$
Pochodna to $1/(1+x^2)$, więc
\$$ \arctan((1-\delta)x)\approx \arctan x- \frac{x\delta}{1+x^2}. \$$
U nas $1-\delta=\cos\varepsilon$, skąd $\delta=1-\cos\varepsilon$, a $x=\tan\lambda_{TS}$, więc
\$$ \arctan(\cos\varepsilon\tan\lambda_{TS})= \lambda_{TS}-(1-\cos\varepsilon) \frac{\tan\lambda_{TS}}{1+\tan^2\lambda_{TS}}, \$$
a korzystając z tożsamości pitagorejskiej $1+\tan^2 x=\sec^2 x$, rozpisując tangens i skracając, mamy
\$$ \lambda_{TS}-(1-\cos\varepsilon) \sin\lambda_{TS}\cos\lambda_{TS}. \$$
Z tożsamości trygonometrycznej $\sin x\cos x= \frac{1}{2}\sin 2x$, mamy
\$$ \alpha_{TS}\approx \lambda_{TS}- \frac{1-\cos\varepsilon}{2}\sin 2\lambda_{TS}. \$$ 

## Wkład ekscentryczności 
<p align="center">
<img src="/assets/images/2026-01-31/rys2.svg" width="500" />
</p>
Wkład ekscentryczności objawia się faktem, że długość ekliptyczna Słońca prawdziwego nie rośnie jednostajnie. Z powyższego rysunku widzimy, że długość ekliptyczna Słońca to $\lambda_{TS}=f-(2\pi-\varpi)$ (kąty wierzchołkowe) $=\varpi+f-2\pi$, gdzie $\varpi$ to <a href="https://en.wikipedia.org/wiki/Longitude_of_periapsis" target=_blank>długość peryhelium</a> orbity Ziemi (kąt między kierunkiem do punktu Barana a kierunkiem do peryhelium), a $f$ to anomalia prawdziwa Ziemi. Punkt w ognisku elipsy to oczywiście Słońce.

Do wyznaczenia anomalii prawdziwej potrzebujemy anomalię mimośrodową $E$, którą możemy obliczyć rozwiązując *równanie Keplera*:
\$$ E-e\sin E=M, \$$
gdzie $e$ to mimośród orbity Ziemi, a $M$ to anomalia średnia, która jest zdefiniowana jako
\$$ M = \frac{2\pi}{T_a}t_p, \$$
gdzie $T_a$ to rok anomalistyczny, czyli czas od peryhelium do peryhelium, a $t_p$ to czas od ostatniego przejścia przez peryhelium. Możemy powiązać ją z rektascencją Słońca średniego, która dana jest wzorem
\$$ \alpha_{MS} = \frac{2\pi}{T_z}t, \$$
gdzie $T_z$ to rok zwrotnikowy (od równonocy wiosennej do równonocy wiosennej), a $t$ to czas od ostatniej równonocy wiosennej. W naszym przypadku możemy założyć, że $T_z\approx T_a=T$. Z tego powodu $\alpha_{MS}$ i $M$ rosną w tym samym tempie, tzn. muszą być równe z dokładnością co do stałej. Wiemy ponadto, że w chwili, gdy Ziemia jest w perygeum, czyli $M=0$, $\alpha_{MS}$ będzie równe w przybliżeniu $\varpi$ - jeśli założymy, że nachylenie równika i ekscentryczność (w tym przypadku) są pomijanie małe, co jest prawdą w przypadku Ziemi. Mamy wtedy
\$$ \alpha_{MS}=M+\varpi. \$$


Wracając do równania Keplera, przybliżymy jego rozwiązanie iteracją prostą. Ponieważ orbita Ziemi jest mało eliptyczna, czyli $e\approx 0$, możemy oszacować początkową wartość $E$ jako
\$$ E_0=M+e\sin E_0\approx M. \$$
Pierwsza iteracja daje nam
\$$ E_1=M+e\sin M\approx E, \$$
na czym przystaniemy, ponieważ będziemy pomijać wyrazy rzędu $O(e^2)$. Anomalię prawdziwą możemy wyznaczyć ze wzoru:
\$$ \sin f= \sqrt{1-e^2}\frac{\sin E}{1-e\cos E}. \$$
Ponieważ pomijamy wyrazy rzędu $O(e^2)$, $\sqrt{1-e^2}\approx 1$, a drugi wyraz w mianowniku jest mały, więc możemy przybliżyć:
\$$ \sin f \approx \sin E(1+e\cos E) \rightarrow f=\arcsin\left((1+e\cos E)\sin E\right). \$$
Z podobną sytuacją spotkaliśmy się wcześniej, lecz z tangensem. Postąpimy podobnie:
\$$ \arcsin\left((1+\delta)\sin{x}\right)\approx \arcsin\sin x + \frac{1}{\sqrt{1-\sin^2 x}}\delta\sin x=x+ \frac{\delta\sin x}{\cos x}, \$$
a u nas $x=E$ i $\delta=e \cos E$, więc
\$$ f \approx E + e\sin E. \$$
Wstawiając $E(M)$:
\$$ f= M+e\sin M+e\sin\left(M+e\sin M\right). \$$
Jeśli przybliżylibyśmy powyższego sinusa, otrzymalibyśmy wyrazy rzędu $O(e^2)$, więc pominiemy po prostu drugi wyraz w jego argumencie, co daje
\$$ f\approx M+2e\sin M. \$$

Wracając do długości Słońca prawidzwego, mamy
\$$ \lambda_{TS}\approx \varpi+M+2e\sin M-2\pi. \$$

## Przybliżona forma równania czasu
Wszystkie wyniki możemy wstawić teraz do równania czasu:
\$$ \tau \approx \varpi+M+2e\sin M-2\pi- \frac{1-\cos\varepsilon}{2}\sin 2(\varpi+M+2e\sin M-\pi)-\alpha_{MS}. \$$
Pamiętając, że $M=\alpha_{MS}-\varpi=2\pi+\alpha_{MS} -\varpi $ (dodanie kąta pełnego nic nie zmienia, a uprości wyrażenie), wiele wyrazów się skraca i upraszcza:
\$$ \tau= 2e\sin (\alpha_{MS}-\varpi) - \frac{1-\cos\varepsilon}{2}\sin 2(\alpha_{MS}+2e\sin M), \$$
gdzie wszystkie kąty wyrażone są oczywiście w radianach (ze względu na stosowane przybliżenia). Ponieważ $e$ jest małe, możemy pominąć drugi wyraz wewnątrz drugiego sinusa:
\$$ \tau\approx  2e\sin (\alpha_{MS}-\varpi) - \frac{1-\cos\varepsilon}{2}\sin 2\alpha_{MS}. \$$
Ostatecznie $\alpha_{MS}=2\pi t/T$, więc
\$$ \boxed{\tau = 2e\sin ( 2\pi\frac{t}{T}-\varpi) - \frac{1-\cos\varepsilon}{2}\sin \left(4\pi \frac{t}{T}\right).} \$$
Wynik jest wyrażony w radianach, więc przekształcamy go na godziny mnożąc razy $12^h/\pi$.
 
Dla Ziemi $\varepsilon=23\degree 26'$, $e=0.0167$ (są małe, więc nasze przybliżenia będą prawidłowe), $\varpi = 283\degree$ oraz $T=365.25^d$. Jeśli wstawimy te dane do powyższego wzoru i zależność $\tau(t)$ umieścimy na wykresie, otrzymamy następujący rezultat:
<p align="center">
<img src="/assets/images/2026-01-31/wykres.svg" width="800" />
</p>
Chwila $t=0$ odpowiada równonocy wiosennej, która ma przeważnie miejsce 80 dni po 1 stycznia, więc wykres został przesunięty tak, aby zaczynał się z początkiem roku.

Można również postąpić na odwrót: w ciągu roku prowadzić obserwacje równania czasu, a następnie przeprowadzić <a href="https://bwegrzyn0.github.io/narz%C4%99dzia%20matematyczne/transformacja-fouriera" target=_blank>transformację Fouriera</a> otrzymanej funkcji - możemy wyznaczyć wtedy $e$, $\varepsilon$ oraz $\varpi$.

