-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : lun. 23 jan. 2023 à 16:30
-- Version du serveur : 10.5.15-MariaDB-0+deb11u1
-- Version de PHP : 7.4.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `Arduino`
--

-- --------------------------------------------------------

--
-- Structure de la table `bouton`
--

CREATE TABLE `bouton` (
  `ID` int(11) NOT NULL,
  `etatbouton` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `distance`
--

CREATE TABLE `distance` (
  `ID` int(11) NOT NULL,
  `distance` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `User`
--

CREATE TABLE `User` (
  `IDUser` int(11) NOT NULL,
  `Login` varchar(100) NOT NULL,
  `MDP` varchar(100) NOT NULL,
  `IsAdmin` tinyint(4) NOT NULL DEFAULT 0 COMMENT '1 : admin. 0 : autre'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `User`
--

INSERT INTO `User` (`IDUser`, `Login`, `MDP`, `IsAdmin`) VALUES
(1, 'admin', 'admin', 1),
(2, 'test', 'test', 0),
(4, 'test2', 'test9', 0),
(5, 'rene', 'rene', 0);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `bouton`
--
ALTER TABLE `bouton`
  ADD PRIMARY KEY (`ID`);

--
-- Index pour la table `distance`
--
ALTER TABLE `distance`
  ADD PRIMARY KEY (`ID`);

--
-- Index pour la table `User`
--
ALTER TABLE `User`
  ADD PRIMARY KEY (`IDUser`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `bouton`
--
ALTER TABLE `bouton`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `distance`
--
ALTER TABLE `distance`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `User`
--
ALTER TABLE `User`
  MODIFY `IDUser` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
