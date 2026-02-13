---
layout: post
title: "Ruch wsteczny Słońca na niebie"
date: 2026-02-12
categories: Astronomia
katex: true
---

Czy możliwe jest, aby na którejkolwiek z planet Układu Słonecznego Słońce zaszło, a następnie od razu wzeszło, wszystko po zachodniej stronie nieba? Aby zjawisko takie miało miejsce, chwilowa prędkość ruchu Słońca po ekliptyce planety musi być większa niż prędkość obrotu sfery niebieskiej, wynikającej z obrotu planety wokół własnej osi. 

## Dla których planet może zajść ruch wsteczny Słońca?
Kąt godzinny Słońca możemy wyrazić wzorem 
\$$ h=\Theta-\alpha, \$$
gdzie $\Theta$ to lokalny czas gwiazdowy, a $\alpha$ to jego rektascensja. Aby Słońce poruszało się po niebie ruchem wstecznym, musi zajść warunek
\$$ \dot{h}<0 \rightarrow \dot{\Theta}<\dot{\alpha}. \$$

Obrót planety na krótkich skalach czasowych jest w przybliżeniu jednostajny, więc z łatwością możemy obliczyć tempo przyrostu czasu gwiazdowego:
\$$ \dot{\Theta} = \frac{24^h}{P_d}, \$$
gdzie $P_d$ to okres obrotu planety wokół własnej osi.

Szybkość zmian rektascensji Słońca jest zależna od szybkości zmian jego długości ekliptycznej. W <a href="https://bwegrzyn0.github.io/astronomia/rownanie-czasu" target=_blank>artykule o równaniu czasu</a> wyprowadziliśmy zależność prawdziwą dla małych nachyleń ekliptyki $\varepsilon$ (co jest prawdą dla większości planet, oprócz Urana):
\$$ \alpha=\lambda- \frac{1-\cos\varepsilon}{2}\sin{2\lambda}. \$$
Zakładamy również cały czas, że orbity wszystkich planet leżą w przybliżeniu w płaszczyźnie ekliptyki.
Biorąc pochodną czasową mamy
\$$ \dot{\alpha}=\dot{\lambda}\left[1 - \left(1-\cos\varepsilon\right)\cos{2\lambda}\right]. \$$
Szybkość zmian długości ekliptycznej Słońca jest równa szybkości zmian anomalii prawdziwej planety na orbicie, $f$, ponieważ kąty te różnią się jedynie o stały czynnik. Szybkość zmian $f$ możemy obliczyć, znając odległość planety od Słońca i jej prędkość. <a href="https://bwegrzyn0.github.io/mechanika/prawa-keplera" target=_blank>Odległość od Słońca na orbicie keplerowskiej</a> to (z $f=0$ w peryhelium):
\$$ r = \frac{a(1-e^2)}{1+e\cos f}, \$$
gdzie $e$ to mimośród orbity, a $a$ to półoś wielka. Całkowita energia ciała na jednostkę masy na takiej orbicie to
\$$ E= -\frac{GM}{2a}, \$$
gdzie $M$ to masa Słońca. Wynosi ona również
\$$ E= \frac{1}{2}v^2- \frac{GM}{r}, \$$
gdzie $v$ to prędkość ciała, gdy jest ono w odległości $r$ od Słońca. Przyrównując dwa wcześniejsze wyrażenia i przekształcając otrzymujemy *równanie vis-viva*:
\$$ v= \sqrt{ GM\left( \frac{2}{r}- \frac{1}{a}\right)}. \$$
Możemy teraz obliczyć $\dot{f}=\dot{\lambda}$:
\$$ \dot{\lambda}= \frac{v\sin\theta}{r}= \frac{\sin\theta}{r} \sqrt{ GM\left( \frac{2}{r}- \frac{1}{a}\right)}, \$$
gdzie $\theta$ to kąt między wektorem $ \mathbf{v}$ a wektorem wodzącym ciała od ogniska elipsy (musimy zrzutować prędkość na jej styczną składową, aby wyznaczyć prędkość kątową ciała).

Aby sprawdzić, czy wspomniany na początku warunek zachodzi, weźmiemy największe możliwe $\dot{\alpha}$, więc zarazem największe możliwe $\dot{\lambda}$. Będzie to spełnione, gdy $r$ będzie najmniejsze (bo mamy $1/r$), czyli w peryhelium. Wstawiając do wcześniejszego wzoru $f=0$ otrzymujemy $r=a(1-e)$ i wiedząc, że z geometrii elipsy wynika fakt, że w peryhelium $\theta=\pi/2$, otrzymujemy po prostych przekształceniach
\$$ \dot{\lambda}= \sqrt{ \frac{GM(1+e)}{a^3(1-e)^3}}. \$$
Wyrażenie pod pierwiastkiem przypomina III prawo Keplera:
\$$ a^3 = \frac{GM}{4\pi^2}P_o^2 \rightarrow \frac{GM}{a^3}= \frac{4\pi^2}{P_o^2}, \$$
gdzie $P_o$ to okres orbitalny planety. Wstawiając, mamy
\$$ \dot{\lambda} = \frac{2\pi}{P_o}\sqrt{ \frac{1+e}{(1-e)^3}}, \$$
wszystko oczywiście dla peryhelium.

Wracając do wcześniejszej nierówności,
\$$ \frac{24^h}{P_d}<\frac{2\pi}{P_o}\sqrt{ \frac{1+e}{(1-e)^3}}, \$$
a ponieważ $24^h=2\pi$, 
\$$ \frac{P_o}{P_d}<\sqrt{ \frac{1+e}{(1-e)^3}}. \$$
Ponieważ $e$ dla wszystkich planet jest mniejsze niż $\approx 0.2$ (mimośród Merkurego), pierwiastek będzie rzędu $1$. Szukamy zatem planet, dla których okres orbitalny i długość dnia syderycznego są porównywalne. Tylko dwie planety spełniają ten warunek - Merkury i Wenus. 

Dla Wenus[^1] mamy $P_o=224.7^d$, $P_d=243.019^d$, lecz obrót planety jest wsteczny do jej ruchu orbitalnego. Z tego powodu kąt godzinny Słońca zwiększa się w tym samym kierunku, co jego rektascensja i analizowane zjawisko nie ma prawa zajść.

Dla drugiego kandydata, Merkurego, $P_o=87.97^d$, $P_d=58.646^d$, więc lewa strona nierówności to $\approx 1.50$ (okresy te są w rezonansie $3:2$). Z kolei $e=0.2056$, skąd prawa strona równania to $\approx 1.55$. Nierówność jest zatem spełniona, więc **na niebie Merkurego możemy obserwować zjawisko ruchu wstecznego Słońca.**

## Wschody i zachody na Merkurym
Wyznaczymy teraz maksymalną wysokość, na którą Słońce wzniesie się nad horyzontem podczas wschodu tuż po zachodzie. Poneważ nachylenie osi obrotu Merkurego do ekliptyki jest równe prawie $0\degree$, a nachylenie jego orbity do tej płaszczyzny to około $7\degree$, cosinus kąta nachylenia jego osi obrotu do płaszczyzny orbity będzie równy $\approx 1$. Wtedy Słońce wzniesie się najwyżej oczywiście na równiku. Wysokość Słońca, gdy jest ono po zachodniej stronie nieba to dla równika
\$$ a=\pi-h, \$$
gdzie $h$ to jego kąt godzinny, który z kolei obliczamy ze wzoru
\$$ h=\Theta-\alpha, \$$
więc
\$$ a=\pi+\alpha-\Theta. \$$
Aby otrzymać szukaną wielkość, obliczymy maksimum tej funkcji.

<a href="https://bwegrzyn0.github.io/astronomia/rownanie-czasu" target=_blank>Z artykułu o równaniu czasu</a> pamiętamy, że długość ekliptyczna Słońca prawdziwego, a zarazem w przypadku Merkurego ($\varepsilon\approx 0\degree$) $\approx$ jego rektascencja, to $\alpha=f+\varpi-\pi$, gdzie $\varpi$ to długość peryhelium oribty Merkurego. Musimy oszacować zależność $f$ od czasu, ponieważ $\Theta$ jest jego funkcją. W tym celu skorzystamy z znanej zależności pomiędzy anomalią mimośrodową i prawdziwą:
\$$ \cos f= \frac{\cos E -e }{1-e\cos E} \rightarrow f=\arccos\left( \frac{\cos E -e }{1-e\cos E}\right). \$$
Ponieważ $e$ jest na ogół małe i bliskie $0$ ($e_{\text{Merkury}}\approx 0.2$), powyższe wyrażenie rozwiniemy w szereg Taylora wokół $e=0$ aż do wyrazów rzędu $O(e^2)$. Obliczamy wartość funkcji i jej pierwszych dwóch pochodnych w $e=0$:
\$$ f(0)=E, \$$
\$$ \frac{df}{de}(0)=\sin E, \$$
\$$ \frac{d^2 f}{de^2}(0)=\sin E\cos E= \frac{1}{2}\sin (2E).\$$
Stąd mamy
\$$ f= E+e\sin E + \frac{1}{4}e^2\sin(2E) + O(e^3). \$$
Aby wyznaczyć $E$ w zależności od $t$, posłużymy się równaniem Keplera:
\$$ E-e\sin E=M, \$$
gdzie $M$ to anomalia średnia zdefiniowana jako
\$$ M= \frac{2\pi}{P_o}t_p, \$$
gdzie $t_p$ to czas od ostatniego prześcia przez peryhelium. Równanie przekształcamy do postaci umożliwiającej iterację prostą:
\$$ E=M+e\sin M, \$$
a ponieważ $e$ jest małe, zgadujemy $E_0=M$. Wtedy
\$$ E_1=M+e\sin M, \$$
\$$ E_2=M+e\sin(M+e\sin M)\approx M+e\sin M+ e(\cos M)(e\sin M)= M+e\sin M + \frac{1}{2}e^2\sin(2M). \$$
Przystaniemy na $E\approx E_2$, ponieważ pomijamy wyrazy $O(e^3)$. Wracając do anomalii prawdziwej:
\$$ f\approx  M+e\sin M + \frac{1}{2}e^2\sin(2M)+e\sin\left( M+e\sin M + \frac{1}{2}e^2\sin(2M)\right)+ \frac{1}{4}e^2\sin\left( 2M+2e\sin M + e^2\sin(2M)\right). \$$
W trzecim sinusie pomijamy wyraz $O(e^2)$ (ponieważ sinus jest pomnożony przez $e$), a w czwartym pomijamy $O(e)$. Wtedy
\$$ f\approx M+e\sin M+ \frac{1}{2}e^2\sin(2M)+e\sin(M+e\sin M)+ \frac{1}{4}e^2\sin(2M). \$$
Jak już wiemy, $\sin(M+e\sin M)\approx \sin M+e\sin M\cos M=\sin M + \frac{1}{2}e\sin (2M)$, więc
\$$ f\approx M+2e\sin M+ \frac{5}{4}e^2\sin(2M). \$$
Pierwsze 2 wyrazy odpowiadają naszemu wynikowi <a href="https://bwegrzyn0.github.io/astronomia/rownanie-czasu" target=_blank>z artykułu o równaniu czasu.</a> Pełen szereg $f(M)$ nazywany jest *równaniem środka* (*equation of the center*). 

Wracając do wysokości, mamy
\$$ a=\pi+f+\varpi-\pi-\Theta=f+\varpi-\Theta= \$$
\$$ =M+2e\sin M+ \frac{5}{4}e^2\sin(2M)+\varpi-\Theta, \$$
a wstawiając zależność $M(t_p)$ otrzymamy
\$$ a= \frac{2\pi}{P_o}t_p+2e\sin \left(\frac{2\pi}{P_o}t_p\right) + \frac{5}{4}e^2\sin\left(\frac{4\pi}{P_o}t_p\right)+\varpi-\Theta. \$$
Od teraz $t_p$ oznaczamy jako $t$. Zauważmy, że $\Theta$ zależy od niego z dokładnością co do stałej, a wszystkie stałe możemy złączyć w jedną:
\$$ a= \frac{2\pi}{P_o}t+2e\sin\left( \frac{2\pi}{P_o}t\right)+ \frac{5}{4}e^2\sin\left( \frac{4\pi}{P_o}t\right)- \frac{2\pi}{P_d}t +C. \$$

Chcemy, aby Słońce zatrzymało się dokładnie w chwili zachodu, czyli pomijając średnicę jego tarczy, gdy $a=0\degree$. Wtedy również $\dot{a}$ ma być równe 0. Obliczmy tę pochodną:
\$$ \dot{a}=\frac{2\pi}{P_o}- \frac{2\pi}{P_d}+ \frac{4\pi e}{P_o}\cos\left( \frac{2\pi}{P_o}t\right) + \frac{5\pi e^2}{P_o}\cos\left( \frac{4\pi}{P_o}t\right). \$$
Aby obliczyć miejsce zerowe, $t_0$, przyrównujemy do $0$ i przekształcamy do postaci umożliwiającej iterację prostą:
\$$ t_0 = \frac{P_o}{4\pi}\arccos\left( \frac{1}{5e^2}- \frac{4}{5e}\cos\left( \frac{2\pi t_0}{P_o}\right)\right) \$$
(skorzystałem z faktu, że $P_o/P_d\approx 3/2$ dla Merkurego). Wartości zbiegają bardzo wolno i oscylują pomiędzy około $2.851$ i $2.807$, dlatego weźmiemy ich średnią: $t_0\approx 2.829^d$. Z struktury powyższego równania widać, że rozwiązania są symetryczne względem $x=0$, tzn. jeśli rozwiązanie to $x$, to $-x$ jest również rozwiązaniem. Dlatego $-t_0$ odpowiada chwili, gdy Słońce jest na horyzoncie i się zatrzymuje, a $t_0$ odpowiada chwili, gdy zawraca z ruchu wstecznego i ponownie zaczyna zmierzać w kierunku zachoda (czyli jest najwyżej). Chcemy, aby $a(-t_0)=0\degree$, więc stała $C$ to
\$$ C=2\pi t_0\left( \frac{1}{P_o}- \frac{1}{P_d}\right)+2e\sin\left( \frac{2\pi}{P_o}t_0\right)+ \frac{5}{4}e^2\sin\left( \frac{4\pi}{P_o}t_0\right), \$$
skąd $C\approx 0.00227$. Wtedy ostateczna odpowiedź to
\$$ a(t_0)\approx 16'. \$$
Niestety, okazuje się że jest to wynik około 4-krotnie zbyt mały! W naszym wyprowadzeniu pomijaliśmy wyrazy rzędu $O(e^3)$ - okazuje się jednak, że $e^3\approx 0.008\approx 28'>a(t_0)$, więc wyrazy te **nie są pomijalne**. 

Przedstawione powyżej rozumowanie można dalej stosować, aby uzyskać wyrażenie na $f(M)$ z dokładnością do wyrazów rzędu $O(e^3)$. Dostaniemy wtedy
\$$ f\approx M+2e\sin M+ \frac{5}{4}e^2\sin(2M)+ \frac{e^3}{12}\left(13\sin (3M)-3\sin M\right). \$$
Podobnie jak wcześniej, 
\$$ a= 2\pi t \left( \frac{1}{P_o}- \frac{1}{P_d}\right)+2e\sin\left( \frac{2\pi}{P_o}t\right)+ \frac{5}{4}e^2\sin\left( \frac{4\pi}{P_o}t\right)+ \frac{e^3}{12}\left(13\sin\left( \frac{6\pi}{P_o}t\right)-3\sin\left( \frac{2\pi}{P_o}t\right)\right)+C. \$$
Miejsca zerowe pochodnej tej funkcji to $t_0=\pm 3.993^d$, więc $C=0.00813$, a stąd
\$$ \boxed{a(t_0)\approx 56',} \$$
co znacznie lepiej odpowiada rzeczywistej wartości (stwierdzonej na podstawie symulacji w programie Stellarium). Przy wyrazach wyższych rzędów znajdują się coraz większe mianowniki, np. wyrazy rzędu $O(e^4)$ są poprzedzone czynnikiem $e^4/96\approx 0.06'\ll a(t_0)$.


[^1]: Wszystkie dane pochodzą z: Karttunen, H., Kröger, P., Oja, H., Poutanen, M., Donner, K. J., & Pwn, W. N. (2020). Astronomia ogólna, Tabela C.9 i C.11.


