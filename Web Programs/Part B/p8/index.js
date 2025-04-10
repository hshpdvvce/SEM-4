document.addEventListener("DOMContentLoaded", function () {
    const outputDiv = document.getElementById("output");

    // Fetch data from the local JSON file
    fetch("index.json")
        .then(response => response.json())
        .then(data => {
            // Display the data in the outputDiv
            outputDiv.innerHTML = "<h2>Student Information</h2>";
            data.forEach(student => {
                outputDiv.innerHTML += `<p><strong>Name:</strong> ${student.studentName} <strong>USN:</strong> ${student.USN}</p>`;
            });
        })
        .catch(error => {
            console.error("Error fetching data:", error);
            outputDiv.innerHTML = "<p>Error fetching data. Please try again later.</p>";
        });
});