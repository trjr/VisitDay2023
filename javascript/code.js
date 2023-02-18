function visitDay() { /* we cover */

  /* this function creates a rectangle at the initial position X/Y and with the color */
  function addRectangle(posX, posY, color, size = 50){
    /* we define a rectangle using the following properties */
    var rectangle = {
      posX: posX,
      posY: posY,
      color: "rgb(" + color[0] + "," + color[1] + "," + color[2] + ")",
      size: size // width and height
    };
    rectangles.push(rectangle);
  } /* end function addRectangle */

  function prepareScene(frame) {
    /* just two variables storing the width/height of the frame*/
    var width = canvas.width;
    var height = canvas.height;
    /* This example just adds one rectangle */
    /* The color is specified as RGB = Red/Green/Blue component between 0 - 255*/
    /* We can set the size optionally using a named parameter */
    addRectangle(50, 50, [0, 0, 0], size=50)

    /* To print anything on the console for debugging, use: */
    console.log("This is a message from frame: " + frame + " - " + width)
  }


  /* WARNING: You should not have to read any code below (except the solutions, if you want them ^-^)*/

  function draw(){
    /* you should not have to modify this function */
    for (var i = 0; i < rectangles.length; i++) {
      var c = rectangles[i];
      context.fillStyle = c.color;
      context.beginPath();
      context.rect(c.posX, c.posY, c.size, c.size);
      context.fill();
    }
  }

  /* current rectangles */
  var rectangles = [];
  var frame = 0;

  function renderFrame(){
    frame = frame + 1
    rectangles = [];
    context.clearRect(0, 0, canvas.width, canvas.height);
    prepareScene(frame);
    draw(); // call draw
    setTimeout(renderFrame, 50);
  }

  renderFrame();
} /* end function makeRectangles */

/* global variables */
var canvas = $("#myCanvas").get(0);
var context = canvas.getContext("2d");
visitDay();


/* WARNING here come the solutions !!! */


  /* Initial code for your reference
  function prepareScene(frame) {
    var width = canvas.width;
    var height = canvas.height;
    addRectangle(50, 50, [0, 0, 0], size=50)
    console.log("This is a message from frame: " + frame + " - " + width)
  }
  */


/*
  // a) Change over time
  // There are different options

  // E.g., change the color over time:
  function prepareScene(frame) {
    // The color is specified as a component between 0 - 255
    // we use frame * 5 to speed up the process and use the modulo therafter to make it toggle to black again
    addRectangle(50, 50, [ (frame*5) % 255, 0, 0])
  }



  // a) Change position over time
  function prepareScene(frame) {
    var posX;
    if (frame % 2 == 0){
      posX = 10;
    }else{
      posX = 15;
    }
    addRectangle(posX, 50, [ 255, 0, 0]);
  }




  // b) Move the rectangle from left to right but it will move out the right window
  function prepareScene(frame) {
    var posX = frame * 10;
    addRectangle(posX, 50, [ 255, 0, 0]);
  }




  // b) Advanced bounce back and forth

  // partial solution, move back to left when we reach the right side

  function prepareScene(frame) {
    var rsize = 50; // rectangle width
    // we reach with the right side of the rectangle the right side of the screen
    var path = (canvas.width - rsize);
    var posX = frame * 10 % path;
    addRectangle(posX, 50, [ 255, 0, 0], rsize);
  }

  // move correctly back and forth, need to think about the path we move
  function prepareScene(frame) {
    var rsize = 50; // rectangle width
    // need to move left to right, then right to left
    var path = (canvas.width - rsize) * 2;
    var posX = frame * 10 % path;
    if ( posX + rsize > canvas.width){
      // move right to left
      posX = path - posX;
    }
    addRectangle(posX, 50, [ 255, 0, 0], rsize);
  }





  c) Create 5 rectangles

  function prepareScene(frame) {
    for(var r = 0; r < 5; r++){
      var posY = 20*r;
      addRectangle(50, posY, [ 255, 0, 0], size = 20);
    }
  }



  d) Create 5 rectangles with different colors

  function prepareScene(frame) {
    for(var r = 0; r < 5; r++){
      var posY = 20*r;
      addRectangle(50, posY, [ r * 50, 50, r * 50], size = 20);
    }
  }


  e) Create 5 rectangles with different colors, where the color varies depending on the frame

  // one pattern, just varying the green of each rectangle the same
  function prepareScene(frame) {
    for(var r = 0; r < 5; r++){
      var posY = 20*r;
      addRectangle(50, posY, [
        (r * 50),
        frame * 10 % 255,
        (r * 50)
      ], size = 20);
    }
  }

  // shifting the same colors around, use an icy theme
  function prepareScene(frame) {
    colors = [ [255,255,255], [220,220,230], [200,200,220], [220,220,230], [240, 240, 250] ]
    for(var r = 0; r < 5; r++){
      var posY = 20*r;
      addRectangle(50, posY, colors[(r + frame) % 5 ], size = 20);
    }
  }



  f) Organize a 2D field of 5x5 rectangles

  function prepareScene(frame) {
    // we need two nested loops to cover X and Y axis
    var size = 25;
    for(var x = 0; x < 5; x++){
      for(var y = 0; y < 5; y++){
        var color = [x * 50, y*50, 50];
        addRectangle(size*x, size*y, color, size = size);
      }
    }
  }

  // icy theme 2D
  function prepareScene(frame) {
    colors = [ [255,255,255], [220,220,230], [200,200,220], [220,220,230], [240, 240, 250] ]
    // we need two nested loops to cover X and Y axis
    var size = 25;
    for(var x = 0; x < 5; x++){
      for(var y = 0; y < 5; y++){
        addRectangle((size*2)*x, size*y, colors[(y + x + frame) % 5], size = size);
      }
    }
  }

  f) Advanced: create a chessboard

  function prepareScene(frame) {
    var width = canvas.width;
    var height = canvas.height;
    var size = 25;
    // we need two nested loops to cover X and Y axis
    for(var x = 0; x <= width/size; x++){
      for(var y = 0; y <= height/size; y++){
        var color = [255,255,255];
        if( (x+y) % 2 == 1){
          color = [0,0,0]
        }
        addRectangle(size*x, size*y, color, size = size);
      }
    }
  }

  g) EXTRA Cool flying rectangles

  function prepareScene(frame) {
  	var size = 25;
    var w = canvas.width / 2 - size;
    var h = canvas.height / 2 - size;

    posX = Math.sin(frame % 30/30 * Math.PI * 2)
    posY = Math.cos(frame % 30/30 * Math.PI * 2)
    addRectangle(posX * w + w, posY * h + h, [frame * 5 % 200 + 50, (frame * 5 + 100) % 200 + 50 ,0], size = size);
  }

*/
