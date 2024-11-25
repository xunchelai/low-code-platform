const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const PORT = 3000;

app.use(bodyParser.json());

// Endpoint to handle incoming messages
app.post('/api/message', (req, res) => {
  const userMessage = req.body.message;
  console.log('Received message:', userMessage);

  // Simple response logic
  const reply = `You said: ${userMessage}`;
  res.json({ reply });
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
