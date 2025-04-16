const quizData = [
    {
        question: "What is the capital of France?",
        options: ["Berlin", "Madrid", "Paris", "Lisbon"],
        answer: "Paris"
    },
    {
        question: "Which language is used for web development?",
        options: ["Python", "HTML", "Java", "C++"],
        answer: "HTML"
    },
    {
        question: "Who wrote 'Hamlet'?",
        options: ["Charles Dickens", "William Shakespeare", "Mark Twain", "Jane Austen"],
        answer: "William Shakespeare"
    }
];

let currentQuestionIndex = 0;
let score = 0;

function loadQuestion() {
    const currentQuestion = quizData[currentQuestionIndex];
    document.getElementById('question').textContent = currentQuestion.question;
    const optionsContainer = document.getElementById('options');
    optionsContainer.innerHTML = '';
    document.getElementById('next-btn').style.display = 'none';

    currentQuestion.options.forEach(option => {
        const optionElement = document.createElement('div');
        optionElement.classList.add('option');
        optionElement.textContent = option;
        optionElement.onclick = () => checkAnswer(optionElement, currentQuestion.answer);
        optionsContainer.appendChild(optionElement);
    });
}

function checkAnswer(selectedElement, correctAnswer) {
    const options = document.querySelectorAll('.option');
    options.forEach(option => {
        option.classList.add('disabled');

        if (option.textContent === correctAnswer) {
            option.classList.add('correct');
        } else if (option.textContent !== correctAnswer) {
            option.classList.add('wrong');
        }
    });

    if (selectedElement.textContent === correctAnswer) {
        score++;
        document.getElementById('score').textContent = `Score: ${score}`;
    }

    document.getElementById('next-btn').style.display = 'block';
}

function nextQuestion() {
    currentQuestionIndex++;
    if (currentQuestionIndex < quizData.length) {
        loadQuestion();
    } else {
        alert(`Quiz Over! Your final score is ${score}/${quizData.length}`);
        location.reload(); // Optional: restart quiz
    }
}

loadQuestion();
