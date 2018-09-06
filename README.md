# morris
Play Nine Men's Morris against computer

https://en.wikipedia.org/wiki/Nine_men%27s_morris

![screenshot](https://github.com/JamesBremner/morris/blob/master/doc/Capture.PNG)

1. Display decorative board with positions and mill lines.
1. Display configuration dialog offering variants( standard or Lasker ) and computer play level ( 1 or 2, 2 has better play )
1. When use clicks OK, start in 'placing' phase or 'Lasker' phase.
1. In placing phase, user places red piece by clicking on empty position with mouse button
2. In placing phase, computer replies by placing blue piece so as to prevent user completing mill if it can, otherwise on random empty position
1. When nine pieces placed by each player, change to moving phase.
1. In moving phase, user moves red piece by clicking on it, then on adjacent empty destination
1. In moving phase, computer replies by moving a random piece to a random empty adjacent point.
1. In Lasker phase, user can either place a piece by clicking on an empty point, so long as pieces remain unplaced, or click a piece to move it.
3. If either player achieves mill, three pieces in a line, pop-up displays success message
1. If user achieves mill, remove one of computer pieces by clicking on it
1. If computer achieves mill, one of user's pieces at random will be removed
