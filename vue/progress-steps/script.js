const progress=document.getElementById('progress');
const prev=document.getElementById('prev');
const next=document.getElementById('next');
const circles=document.querySelectorAll('.circle');

let currentAction=1;

next.addEventListener('click',()=>{
    currentAction++;
    if(currentAction>circles.length){
        currentAction=circles.length;
    }
    update();
})

prev.addEventListener('click',()=>{
    currentAction--;
    if(currentAction<1){
        currentAction=1;
    }
    update();
})

function update(){
    circles.forEach((circle,idx)=>{
        if(idx<currentAction){
            circle.classList.add('active');
        }else{
            circle.classList.remove('active');
        }
    })

    const actives=document.querySelectorAll('.active');
    progress.style.width=(actives.length-1)/(circles.length-1)*100+'%';

    if(currentAction===1){
        prev.disabled=true;
    }else if(currentAction===circles.length){
        next.disabled=true;
    }else{
        prev.disabled=false;
        next.disabled=false;
    }
}