<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Resposta</title>
</head>
<body>
    <?php
    if (isset($_POST['name']) && isset($_POST['email'])) {
        $name = htmlspecialchars($_POST['name']);
        $email = htmlspecialchars($_POST['email']);
        echo "Welcome <strong>$name</strong>!<br>";
        echo "Your email address is: <strong>$email</strong>";
    } else {
        echo "Por favor, preencha todos os campos.";
    }
    ?>
</body>
</html>