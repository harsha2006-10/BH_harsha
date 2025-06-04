function changeNews() {
        const region = document.getElementById('region').value;
        alert(`News updated for region: ${region}`);
}
function ok()
{
    const password = document.getElementById('password').value;
    const confirmPassword = document.getElementById('conform password').value;
    if (password !== confirmPassword) {
        alert("Passwords do not match!");
        return false;
    }
    alert("Signed up successfully!");
    window.location.href = ".vscode/project.html"; 
}
function okk() {
        alert("login successfully!");
    window.location.href = ".vscode/project.html";
}
function handleSearch(event) {
    event.preventDefault();
    const query = document.querySelector('input[name="q"]').value.trim().toLowerCase();
    if (query === "cricket") {
        window.location.href = "cricket.html";
    } else if (query === "indian") {
        window.location.href = "indian.html";
    } else if (query === "amity" || query === "aub") {
        window.location.href = "AUB.html";
    } else {
        alert("No results found for: " + query);
    }
}
function sharePage() {
    if (navigator.share) {
        navigator.share({
            title: document.title,
            text: "Check out this awesome website: BOOSTER!",
            url: window.location.href
        }).then(() => {
            alert('Thanks for sharing!');
        }).catch((err) => {
            alert('Could not share: ' + err);
        });
    } else {
        prompt("Copy and share this link:", window.location.href);
    }
}
document.addEventListener('DOMContentLoaded', function() {
    // Prevent navigation for "Back to Home" on AUB.html
    const backToHome = document.getElementById('backToHome');
    if (backToHome) {
        backToHome.addEventListener('click', function(event) {
            event.preventDefault();
            alert('Navigation stopped! You are still on this page.');
        });
    }

    // Prevent navigation for "Back to Home" on cricket.html
    const backToHomeCricket = document.getElementById('backToHomeCricket');
    if (backToHomeCricket) {
        backToHomeCricket.addEventListener('click', function(event) {
            event.preventDefault();
            alert('Navigation stopped! You are still on this page.');
        });
    }

    // Prevent navigation for "Back to Home" on indian.html
    const backToHomeIndian = document.getElementById('backToHomeIndian');
    if (backToHomeIndian) {
        backToHomeIndian.addEventListener('click', function(event) {
            event.preventDefault();
            alert('Navigation stopped! You are still on this page.');
        });
    }
});

