# Clock Design

![Design](https://github.com/yashaswiim/machineLab/blob/main/6March/imgs/design1.jpg)
![Design](https://github.com/yashaswiim/machineLab/blob/main/6March/imgs/design2.jpg)
![Design](https://github.com/yashaswiim/machineLab/blob/main/6March/imgs/design3.jpg)

The theme of this design is related to the UAE because it is trying to depict pearl diving, one of the major ancient economic activities of the UAE. It is a tradition dating back more than 7000 years ago and it was once the driving force of the UAE economy. It is also believed to be the basis of the foundation of Dubai and Abu Dhabi.

The mechanism will be as follows:

The diver will rotate along the circle every half hour. It starts with the pearl shell hidden at the beginning. On completion of the first half of the hour, when the diver reaches the bottom of the circle, the stick holding the pearl will rotate to show the shell on top of the diver's hand. Then on completion of the second half of the hour, the shell opens to reveal the pearls inside the shell. The pearls will display for a few seconds and the shell will close again and the stick will rotate to hide the shell as well. And the cycle repeats for the next hour.

For this mechanism, three motors are required. The first motor is required to rotate the diver and the second motor is required to rotate the stick holding the shell. Another motor is required to open the shell containing the pearls once the hour completes.

### Motors/Sensors

For rotating the diver, a stepper motor can be used as it would give excellent position accuracy. Its lower speed compared to other motors would not be an obstruction here because we would not want the diver to rotate very fast anyways in order make it more realistic and to give the viewers a chance to watch the process of the diver reaching the bottom of the "ocean" closely and slowly.

![]()

For rotating the stick, a servo motor can be used because 180 degrees movement would be sufficient for this mechanism. 180 degrees rotation can bring the shell from the back to the front or the other way around. The motor will be placed at the edge of the diver's tank such that when the stick is extended, the pearl reaches exactly on top of the diver's hand and when it is retracted, the shell is hidden behind (or even inside) the tank, which has a slit at its back to fit the stick and the shell.

![]()

For opening the shell, a servo motor can be used as well because 90 degrees movement would be sufficient for this mechanism. 90 degrees rotation can open or close the shell as needed. 

[Example](https://www.youtube.com/watch?v=gZDtWOQkfas)

Position sensors can be used to more accurately detect when respective motions need to start by tracking the position of the diver.

### Most difficult mechanism?

I think all three rotations are similar in some sense. But I will sketch more in detail here about the rotation of the stick to show/hide the shell with the pearls. I think this is a bit more difficult because there are more measurement aspects that need to taken care of so that the shell is hidden properly when its not supposed to be visible to the viewer.

![](https://github.com/yashaswiim/machineLab/blob/main/6March/imgs/design4.jpg)

### Audio and Visual Effects

One of the visual effects that might enhance this design is using LEDs instead of the pearls inside the shell. We can have 12 LEDs inside and light a number of them when the shell opens based on what hour has just started on the clock.

### Inspiration and More about pearl diving

![inspiration](https://github.com/yashaswiim/machineLab/blob/main/6March/imgs/inspiration.jpg)

[Pearl Diving Link 1](https://www.bayut.com/mybayut/pearl-diving-uae/)

[Pearl Diving Link 2](https://theculturetrip.com/middle-east/united-arab-emirates/articles/8-things-you-should-know-about-pearl-diving-and-its-history-in-the-uae/)
