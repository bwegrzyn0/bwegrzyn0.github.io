---
layout: post
title: "Wyznaczanie gęstości powietrza za pomocą wahadła matematycznego"
date: 2025-06-18 
categories: mechanika
katex: true
---

## Tłumione wahadło matematyczne
Rozważmy najprostszy model wahadła. Jest to masa punktowa $m$ zawieszona na nieważkiej lince o długości $l$. Na wahadło działa siła ciężkości $\mathbf{Q}$, która rozkłada się na składową radialną i styczną do linki oraz siła reakcji linki $\mathbf{F_r}$, która równoważy $\mathbf{Q_r}$. Na masę działa również siła oporu $\mathbf{F_o}$. Poniżej został przedstawiony schemat tego układu.

<p align="center">
<img src="/assets/images/2025-06-18/wahadlotlumione.svg" width="500" />
</p>

Przy małych prędkościach wartość siły oporu $\mathbf{F_o}$  działającej na naszą masę jest wprost proporcjonalna do prędkości tego ciała. Dlatego założymy, że nasze wahadło porusza się z niewielką prędkością. Pozwoli nam to zapisać 2 zasadę dynamiki jako
\$$ \mathbf{M}=\mathbf{l}\times\mathbf{Q_s}+\mathbf{l}\times\mathbf{F_o}, \$$
gdzie $\mathbf{l}$ to wektor łączący punkt zaczepienia wahadła i masę $m$.

Niech $\hat{\mathbf{n}}$ będzie wektorem jednostkowym leżącym na tym samym kierunku co $\mathbf{Q_s}$ i o zwrocie w lewo. Wtedy $\mathbf{Q_s}=Q_s\hat{\mathbf{n}}$. Wiadomo, że $Q_s=Q\sin\theta=mg\sin\theta$, czyli $\mathbf{Q_s}=mg\sin\theta\,\hat{\mathbf{n}}$. Wtedy $\mathbf{l}\times\mathbf{Q_s}=mg\sin\theta\,\mathbf{l}\times\hat{\mathbf{n}}$. Łatwo zauważyć, że $\mathbf{l}\times\hat{\mathbf{n}}=-l\hat{\mathbf{k}}$, przy czym oś $z$ jest skierowana od ekranu. Zatem $\mathbf{l}\times\mathbf{Q_s}=-mgl\sin\theta\,\hat{\mathbf{k}}$. 

Jak wspomniano wcześniej, $\mathbf{F_o}=-2\beta m\mathbf{v}$, gdzie $\beta$ to pewna stała - współczynnik tłumienia, a czynnik $2m$ ułatwi późniejsze obliczenia. Wiemy, że $\mathbf{v}=\boldsymbol{\dot{\theta}}\times\mathbf{l}$, a $\boldsymbol{\dot{\theta}}=\dot{\theta}\hat{\mathbf{k}}$. Na podstawie reguły prawej ręki możemy stwierdzić, że $\mathbf{v}=-\dot{\theta}l\hat{\mathbf{n}}$, a co za tym idzie $\mathbf{F_o}=2\beta ml\dot{\theta}\,\hat{\mathbf{n}}$. Teraz możemy obliczyć moment siły oporów:
\$$ \mathbf{l}\times\mathbf{F_o}=2\beta ml\dot{\theta}\,{\mathbf{l}}\times\hat{\mathbf{n}}=-2\beta ml^2\dot{\theta}\,\hat{\mathbf{k}}.\$$

Wiemy również, że $\mathbf{M}=I\ddot{\theta}\hat{\mathbf{k}}$, gdzie $I$ to moment bezwładności wahadła wokół punktu zaczepienia. Dla masy punktowej będzie to $ml^2$. Możemy teraz zapisać 2 zasadę dynamiki jako
\$$ ml^2\ddot{\theta}\hat{\mathbf{k}}=-mgl\sin{\theta}\,\hat{\mathbf{k}}-2\beta ml^2\dot{\theta}\,\hat{\mathbf{k}}, \$$
a po podzieleniu przez $ml^2\hat{\mathbf{k}}$ otrzymamy
\$$ \ddot{\theta}+2\beta\dot{\theta}+\frac{g}{l}\sin{\theta}=0. \$$
Gdy $\theta$ jest małym kątem, zachodzi w przybliżeniu równość $\sin\theta\approx\theta$, co pozwala nam zapisać 
\$$ \ddot{\theta}+2\beta\dot{\theta}+\omega_0^2\theta=0, \$$
gdzie $\omega_0=\sqrt{g/l}$.

Równanie charakterystyczne to
\$$ r^2+2\beta r+\omega_0^2=0, \$$
a jego rozwiązania to
\$$ r=-\beta\pm i\omega, \$$
gdzie $\omega=\sqrt{\omega_0^2-\beta^2}$. Rozwiązanie ogólne to wtedy
\$$ \theta=e^{-\beta t}\left(Ae^{i\omega}+Be^{-i\omega}\right), \$$
gdzie $A$ i $B$ to pewne stałe. Zapis ten jest równoważny
\$$ \theta=e^{-\beta t}\left[(A+B)\cos\omega t+(A-B)i\sin\omega t\right]. \$$
$\theta$ musi być liczbą rzeczywistą, dlatego $B=\overline{A}$. Niech $A=a+bi$, wtedy $B=a-bi$. Wstawiając to do powyższego równania otrzymamy
\$$ \theta=e^{-\beta t}\left(2a\cos\omega t-2b\sin\omega t\right). \$$
Ponieważ w nawiasie znajduje się liniowa kombinacja sinusa i cosinusa, możemy zapisać
\$$ \theta=\theta_0 e^{-\beta t}\cos(\omega t+\varphi), \$$
gdzie $\theta_0$ to amplituda drgań, a $\varphi$ to faza.

## Pomiar współczynnika tłumienia
Skonstruowano wahadło z cienkiej, w przybliżeniu nieważkiej nitki oraz śruby zamocowanej na jej końcu. Ponieważ rozmiary śruby były znacznie mniejsze niż długość wahadła, cała masa była w przybliżeniu skoncentrowana w jednym punkcie. Nitka została owinięta wokół cienkiego patyczka służącego jako punkt zaczepienia. Taki sposób zaczepienia linki umożliwił łatwą regulację długości wahadła. Zakładamy, że współczynnik tłumienia jest na tyle mały, że $\omega\approx\omega_0$.

Mierząc wartość $\theta$, gdy $\cos(\omega t+\varphi)=1$ (gdy wahadło jest w swoim maksymalnym wychyleniu) możemy wyznaczyć $\beta$. Czas mierzymy od chwili puszczenia wahadła, więc $\varphi=0$. Warunek zachodzi w bardzo dobrym przybliżeniu dla małych wychyleń (ponieważ $T$ tak naprawdę zależy od amplitudy), gdy $t=nT$, gdzie $T$ to okres wahadła, a $n=0,1,2,\dots$.
\$$		\theta(nT)=\theta_0 e^{-\beta nT} \$$
\$$		\ln{\theta(nT)}=\ln{\theta_0}+-\beta nT \$$
Sporządzając wykres $\ln{\theta(nT)}$ możemy wyznaczyć $\beta$ nawet bez znajomości $\theta_0$, ponieważ będzie to współczynnik kierunkowy prostej najlepszego dopasowania.

Wahadło zostało umieszczone w odległości $d=2$cm od biurka, do którego została przyklejona kartka papieru w kratkę. Aby dokładnie zaznaczać kolejne maksymalne wychylenia wahadła, w odległości $d'>1$m od wahadła zostało umieszczone źródło światła, zgodnie ze schematem.
<p align="center">
<img src="/assets/images/2025-06-18/ukladpom.svg" width="500" />
</p>

Cień rzucany przez linkę różnił się o $\Delta x'$ od prawdziwego jej położenia. Przy wymienionych wcześniej wartościach $d$ i $d'$, $\Delta x'<0.02\Delta x$, zatem błąd jest pomijalny. Błąd związany z wyznaczeniem czasu również został pominięty, ponieważ dla tak małych wychyleń okres był w bardzo dobrym przybliżeniu stały i wahadło służyło jako zegar.

Co 5 okresów na kartce były zaznaczane maksymalne wychylenia wahadła. Następnie została zmierzona odległość linii, na której były zaznaczane kolejne położenia wahadła, od punktu zaczepienia wahadła ($h$), aby wyznaczyć $\tan{\theta}=\Delta x/h$. Ponieważ wychylenia były małe, $\theta\approx\tan{\theta}$. Wyniki pomiarów dla $l=0.8\text{m}$ zostały zestawione na poniższych wykresach.
<p align="center">
<img src="/assets/images/2025-06-18/wykresbeta.svg" width="700" />
</p>

W tym układzie otrzymana wartość $\beta$ to
\$$	\beta = 0.01478\pm0.0002\frac{1}{\text{s}} \$$
Tak mała niepewność wynika z kilku czynników. Niepewność w pomiarze kąta była bardzo niewielka, ponieważ źródło światła umożliwiało precyzyjne wyznaczenie wychylenia wahadła, a ze względu na dużą odległość $h$ zaznaczanych punktów od osi obrotu, niewielkie zmiany kąta powodowały dużą zmianę w odległości $\Delta x$. Niepewność w pomiarze czasu była pomijalna. Niepewność związana z wzięciem logarytmu naturalnego jest dana w przybliżeniu wzorem
\$$	\Delta(\ln x)\approx\frac{\Delta x}{x}. \$$
W tym przypadku $\Delta x$ było rzędu $10^{-3}$, a $x$ rzędu $10^{-1}$, czyli niepewność była rzędu $10^{-2}$.

Współczynniki tłumienia wyznaczone dla wielu wahadeł umieściłem na widocznym poniżej wykresie zależności $\beta(l)$. Okazało się, że w dobrym przybliżeniu punkty pomiarowe układają się na prostej o współczynniku kierunkowym $a=(0.0073\pm0.0019)\frac{1}{\text{sm}}$ i wyrazie wolnym $b=(0.0092\pm0.0012)\frac{1}{\text{s}}$. Jak wyjaśnić tę obserwację?
<p align="center">
<img src="/assets/images/2025-06-18/wykresbetal.svg" width="700" />
</p>

## Wyjaśnienie zaobserwowanej zależności
Można spekulować, że wyraz wolny to część współczynnika tłumienia pochodząca od śruby służącej jako masa na końcu wahadła, a $al$ to wkład pochodzący od nitki.

Prawo Stokesa mówi, że wartość siły działającej na kulę o promieniu $R$ poruszającą się z małą prędkością $v$ w płynie jest dana wzorem
\$$	F_o=6\pi\mu R v, \$$
gdzie $\mu$ to lepkość dynamiczna. Nitkę można przybliżyć jako złożoną z $l/w$ kul o średnicy $w$, gdzie $w$ to również szerokość nitki, ułożonych jedna za drugą. Promień takiej kuli to wtedy $R=w/2$. Całkowita siła działająca na nitkę to suma sił pochodzących od jej wszystkich małych kul. Każda z nich ma jednak inną prędkość, ponieważ znajduje się w innej odległości od osi obrotu.
\$$	F=\sum_{i=0}^{l/w}6\pi\mu\frac{w}{2}v_i=3\pi\mu w\omega\sum_{i=0}^{l/w} r_i, \$$
gdzie $r_i$ to odległość $i$-tej kuli od osi obrotu. Aby obliczyć sumę, zapiszmy
\$$	\sum_{i=0}^{l/w} r_i=\frac{1}{w}\sum_{i=0}^{l/w} r_i w. \$$
Ponieważ $w$ jest małe w porównaniu do $l$, możemy aproksymować sumę jako całkę. Wtedy $w = \Delta r_i$, czyli
\$$	\frac{1}{w}\sum_{i=0}^{l/w} r_i w\approx\frac{1}{w}\int_{0}^{l}r\,dr=\frac{l^2}{2w}.\$$
Wstawiając ten wynik do wcześniejszego wzoru otrzymujemy
\$$	F\approx \frac{3}{2}\pi\mu lv,\$$
gdzie $v$ to prędkość końca wahadła. Ponieważ $F=2\beta m v$, zachodzi równość
\$$
	\beta=\frac{3\pi\mu}{4m}l,
    \$$
co wyjaśnia zaobserwowaną zależność.

## Wyznaczanie lepkości dynamicznej powietrza
Całkowita siła oporu działająca na wahadło to
\$$	F=2\beta mv=2almv+2bmv,\$$
gdzie m to masa śrubki zawieszonej na końcu wahadła (masa nitki jest pomijalna). Pierwszy wyraz po prawej stronie to siła pochodząca od nitki, czyli przyrównując to do wcześniej obliczonej siły otrzymujemy
\$$		2almv=\frac{3}{2}\pi\mu lv \$$
\$$		4am=3\pi \mu \$$
\$$		\mu=\frac{4am}{3\pi}. \$$
Zmierzona masa śrubki to $m=(4\pm 0.5)$g oraz $a=(0.0073\pm0.0019)\frac{1}{\text{ms}}$. Przy tych danych
	\$$ \mu=(12.4\pm4.8)\times 10^{-6}\text{ Pa s},\$$
przy czym tablicowa wartość $\mu$ dla powietrza w temperaturze $293\text{K}$ to $\mu=18.13\times 10^{-6}\text{ Pa s}$.

## Wyznaczanie gęstości powietrza
Kinetyczna teoria gazów daje następujący wzór dla rozrzedzonych gazów:
\$$	\mu=\alpha\rho\lambda\sqrt{\frac{2k_B T}{\pi m}},\$$
gdzie bezwymiarowy współczynnik $\alpha\approx 1$, $\rho$ to gęstość gazu, $\lambda$ to średnia droga swobodna w tym gazie, $T$ to temperatura, a $m$ to masa cząsteczkowa. Przekształćmy ten wzór do postaci
\$$	\rho=\frac{\mu}{\alpha\lambda}\sqrt{\frac{\pi m}{2k_B T}}.\$$
Dla powietrza $m\approx29\text{u}\approx 4.28\times 10^{-26}\text{kg}$, $\lambda\approx6,6\times 10^{-8}$m. Temperatura podczas pomiarów wynosiła ok. $T\approx293\text{K}$. Wstawiając te dane do wzoru otrzymujemy wynik 
\$$	\rho=(0.77\pm0.30)\frac{\text{kg}}{\text{m}^3},\$$
przy czym tablicowa wartość w tej temperaturze to $\rho=1.20\frac{\text{kg}}{\text{m}^3}$. Wynik jest obarczony dużą niepewnością spowodowaną głównie niepewnością $m$ i $\mu$. Należy również zauważyć, że prawdziwa wartość $\rho$ nie mieści się w przedziale niepewności. Jest to najprawdopodobniej spowodowane przybliżeniem nitki jako złożonej z wielu kul. 
