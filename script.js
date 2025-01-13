document.getElementById("jobForm").addEventListener("submit", function(event) {
    event.preventDefault();

    let jobId = document.getElementById("jobId").value;
    let priority = document.getElementById("priority").value;
    let description = document.getElementById("description").value;

    let jobItem = document.createElement("li");
    jobItem.textContent = `Job ID: ${jobId}, Priority: ${priority}, Description: ${description}`;

    document.getElementById("jobList").appendChild(jobItem);
    
    document.getElementById("jobForm").reset();
});

function executeJob() {
    let jobList = document.getElementById("jobList");
    if (jobList.children.length > 0) {
        alert("Executing: " + jobList.children[0].textContent);
        jobList.removeChild(jobList.children[0]);
    } else {
        alert("No jobs to execute.");
    }
}
