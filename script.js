const timer = document.getElementById('timer');
const play = document.getElementById('play-pause');
const reset = document.getElementById('reset');

let seconds = 0;
let minutes = 0;
let hours = 0;

let evenSeconds = 0;
let evenMinutes = 0;
let evenHours = 0;

let timerInterval = null;
let timerStatus = 'stopped';

function countTime () {
    seconds++;
    if (seconds / 60 === 1) {
        seconds = 0;
        minutes++
        if (minutes / 60 === 1) {
            minutes = 0;
            hours++
    }
    }

    if (seconds < 10) {
        evenSeconds = '0' + seconds.toString();
    } else {
        evenSeconds = seconds;
    }    
    if  (minutes < 10) {
        evenMinutes = '0' + minutes.toString();
    } else {
        evenMinutes = minutes;
    } 
    if  (hours < 10) {
        evenHours = '0' + hours.toString();
    } else {
        evenHours = hours;
    }    

    timer.innerText = evenHours + ':' + evenMinutes + ':' + evenSeconds;
}

//window.setInterval(countTime, 1000);

play.addEventListener('click', function(){


    if(timerStatus === 'stopped') {
        timerInterval = window.setInterval(countTime, 1000);
        play.innerHTML = `<i class="fa-solid fa-pause" id='pause'></i>`;
        play.style.background='orange';
        timerStatus = 'started';
    } else {
        window.clearInterval(timerInterval);
        play.innerHTML = `<i class="fa-solid fa-play" id='play'></i>`;
        play.style.background='green';
        timerStatus = 'stopped';
    }    
    //return timerStatus;
})

reset.addEventListener('click', function(){
    
    window.clearInterval(timerInterval);
    seconds = 0;
    minutes = 0;
    hours = 0;

    timer.innerHTML = '00:00:00';
    play.innerHTML = `<i class="fa-solid fa-play" id='play'></i>`;
    play.style.background='green';
    timerStatus = 'stopped';
})
