
function ShowInputValue()
{
	console.log($("#myInput").val());
}

//$("#myInput") ~ document.getElementById("myInput")

$(document).ready(function()
{
	console.log("jq is ready;");
	$("#myInput").change(ShowInputValue);
	
	$("#acs").click(function()
	{
		$("#quickDiv").load("acasa1.html");
	});
	
	//console.log($(".myClass")[1]);
});

var slideIndex = 1;
showSlides(slideIndex);

function plusSlides(n) {
  showSlides(slideIndex += n);
}

function currentSlide(n) {
  showSlides(slideIndex = n);
}

function showSlides(n) {
  var i;
  var slides = document.getElementsByClassName("mySlides");
  if (n > slides.length) {slideIndex = 1}    
  if (n < 1) {slideIndex = slides.length}
  for (i = 0; i < slides.length; i++) {
      slides[i].style.display = "none";  
  }
  slides[slideIndex-1].style.display = "block";  
}
