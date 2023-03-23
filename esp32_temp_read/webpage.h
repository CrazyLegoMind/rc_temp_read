//============
//Webpage Code
//============
String webpageCode = R"***(
<!DOCTYPE html>
<head>
  <title> Temperature Telemetry </title>
</head>
<html>
<!----------------------------CSS---------------------------->
<style>
  body {background-color: rgba(128, 128, 128, 0.884)}
  h4 {font-family: arial; text-align: center; color: white;}
  .card
  {
     max-width: 450px;
     min-height: 100px;
     background: rgba(255, 0, 0, 0.521);
     padding: 10px;
     font-weight: bold;
     font: 25px calibri;
     text-align: center;
     box-sizing: border-box;
     color: blue;
     margin:20px;
     box-shadow: 0px 2px 15px 15px rgba(0,0,0,0.75);
  }
</style>
<!----------------------------HTML--------------------------->
<body>
  <div class="card">
    <h1><span sstyle="color:white">Temperature Telemetry</span></h1>
    <h2>
      Sensor : <span style="color:yellow" id="POTvalue">0</span> C
    </h2>
    <h2>
      Ambient : <span style="color:yellow" id="AmbientC">0</span> C
    </h2>
  </div>
  <h4>
    <button onclick="help()">Help</button><br><br>
    <div id="myDIV"> </div>
  </h4>
<!-------------------------JavaScript------------------------->
  <script>
    setInterval(function()
    {
      getPOTval();
    }, 1000);
    setInterval(function()
    {
      getAmbientC();
    }, 1000);
    //-------------------------------------------------------
    function getPOTval()
    {
      var POTvalRequest = new XMLHttpRequest();
      POTvalRequest.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
          document.getElementById("POTvalue").innerHTML =
          this.responseText;
        }
      };
      POTvalRequest.open("GET", "readPOT", true);
      POTvalRequest.send();
    }
    //-------------------------------------------------------
    function getAmbientC()
    {
      var getAmbientCRequest = new XMLHttpRequest();
      getAmbientCRequest.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
          document.getElementById("AmbientC").innerHTML =
          this.responseText;
        }
      };
      getAmbientCRequest.open("GET", "readAmbient", true);
      getAmbientCRequest.send();
    }
    //-------------------------------------------------------
    function help()
    {
      var x = document.getElementById("myDIV");
      var message = "POT connected to ADC0 : 12-bit value (0 ---> 4095)";
      if (x.innerHTML == "") x.innerHTML = message;
      else x.innerHTML = "";
    }
  </script>
</body>
</html>
)***";